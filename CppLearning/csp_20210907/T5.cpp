#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cassert>
#include<functional>
#include<numeric>
#include<set>
#include<unordered_map>
#include<tuple>
#include<random>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
#define rpp(i,x,e,head) for(int i=head[x];~i;i=e[i].next)
#define dyes cerr<<"yes"<<endl
#define dbg(x) cerr<<#x<<"="<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define pts puts("")
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1LL;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
inline ll readll(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1LL;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
template <class T> inline void chmax(T &a,T b){if(a<b) a=b;}
template <class T> inline void chmin(T &a,T b){if(a>b) a=b;}
inline void swap(int &a,int &b){int c=a;a=b;b=c;}
using namespace std;
#define mst(a,val) memset(a,val,sizeof(a))
#define pii pair<int,int>
#define piii pair<int,pair<int,int> >
#define mp(i,j) make_pair(i,j)
#define fi first
#define sc second
#define inf (0x3f3f3f3f)
#define infl (0x3f3f3f3f3f3f3f3fLL)
#define forvec(i,j) for(vector<int>::iterator i=j.begin();i!=j.end();++i)
#define forvecv(i,j) for(vector<int>::iterator i=--j.end();i>=j.begin();--i)
//=====================head end======================//
const int N=3e5+10;
const int M=1e7+10;
const int P=998244353;
inline int ad(int a,int b){a+=b;if(a>=P)a-=P;return a;}
int sm[N<<2],tg[N<<2];
int pr[M],isp[M],mind[M],cnt;

// 准备素数表
// 这里isp[i]中0表示是素数
// mind 
inline void pre(){
    rep(i,2,M-1){
        if(!isp[i]) pr[++cnt]=i,mind[i]=i;
        rep(j,1,cnt){
            if(i*pr[j]>=M) break;
            isp[i*pr[j]]=1;
            mind[i*pr[j]]=pr[j];
            if(i%pr[j]==0){
                break;
            }
        }
    }
}
inline void pd(int cur,int l,int r,int x){
    sm[cur]=ad(sm[cur],1ll*(r-l+1)*x%P);
    tg[cur]=ad(tg[cur],x);
}
// (x<<1|1) = 2x + 1
inline void pushdown(int cur,int l,int r){
    int mid=(l+r)>>1;
    if(tg[cur]){
        pd(cur<<1,l,mid,tg[cur]);
        pd(cur<<1|1,mid+1,r,tg[cur]);
        tg[cur]=0;
    }
}
inline void upd(int cur,int L,int R,int l,int r,int x){
    if(l<=L&&r>=R){pd(cur,L,R,x);return;}int mid=(L+R)>>1;
    pushdown(cur,L,R);
    if(l<=mid) upd(cur<<1,L,mid,l,r,x);
    if(r>mid) upd(cur<<1|1,mid+1,R,l,r,x);
    sm[cur]=ad(sm[cur<<1],sm[cur<<1|1]);
}
inline int query(int cur,int L,int R,int l,int r){
    if(l<=L&&r>=R){return sm[cur];}int mid=(L+R)>>1;
    pushdown(cur,L,R);
    if(r<=mid) return query(cur<<1,L,mid,l,r);
    else if(l>mid) return query(cur<<1|1,mid+1,R,l,r);
    else return ad(query(cur<<1,L,mid,l,r),query(cur<<1|1,mid+1,R,l,r));
}

int n,q;
bool a[N<<2],tgg[N<<2];
inline void pdd(int cur){
    a[cur]=tgg[cur]=1;
}
inline void pus(int cur){
    if(tgg[cur]) pdd(cur<<1),pdd(cur<<1|1);
}
inline bool ok(int cur,int L,int R,int l,int r){
    if(l<=L&&r>=R){return a[cur];}int mid=(L+R)>>1;
    pus(cur);
    if(r<=mid) return ok(cur<<1,L,mid,l,r);
    else if(l>mid) return ok(cur<<1|1,mid+1,R,l,r);
    else return ok(cur<<1,L,mid,l,r)||ok(cur<<1|1,mid+1,R,l,r);
}
inline void up(int cur,int L,int R,int l,int r){
    if(l<=L&&r>=R){pdd(cur);return;}int mid=(L+R)>>1;
    pus(cur);
    if(l<=mid) up(cur<<1,L,mid,l,r);
    if(r>mid) up(cur<<1|1,mid+1,R,l,r);
    a[cur]=a[cur<<1]||a[cur<<1|1];
}
int main(){
    pre();
    n=read();q=read();
    rep(i,1,n){
        int x=read();
        while(x!=1){
            int t=mind[x];
            upd(1,1,n,i,i,t);
            up(1,1,n,i,i);
            x/=t;
        }
    }
    rep(i,1,q){
        int op=read();
        if(op==1){
            int l=read(),r=read();
            if(!ok(1,1,n,l,r)){
                printf("%d\n",1);
            }else{
                int ret=query(1,1,n,l,r);
                printf("%d\n",ret);
            }
        }else{
            int l=read(),r=read();
            int x=read();
            while(x!=1){
                int t=mind[x];
                upd(1,1,n,l,r,t);
                up(1,1,n,l,r);
                x/=t;
            }
        }
    }
    return 0;
}
