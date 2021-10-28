// 树状数组骚操作
#include <stdio.h>
#include <string.h>
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAX_N 100005
 
typedef long long ll;
 
inline ll max(ll x,ll y){return x>y?x:y;}
 
inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

ll bit0[MAX_N], bit1[MAX_N], n, m;

ll sum(ll *b, int i){
    ll s = 0;
    while(i>0){
        s += b[i];
        i -= i & -i;
    }
    return s;
}

void add(ll *b, int i, ll v){
    while(i <= n){
        b[i] += v;
        i += i & -i;
    }
}

int main(){
    n = read(), m = read();
    rep(i, 1, n){
        add(bit0, i, read());
    }
    int c;
    ll x, y, k;
    rep(i, 1, m){
        c = read();
        if(c==1){
            x = read(), y = read(), k = read();
            add(bit0, x, -k*(x-1));
            add(bit1, x, k);
            add(bit0, y+1, y*k);
            add(bit1, y+1, -k);
        }else{
            x = read(), y = read();
            ll res = 0;
            res += sum(bit0, y) + sum(bit1, y)*y;
            res -= sum(bit0, x-1) + sum(bit1, x-1)*(x-1);
            printf("%lld\n", res);
        }
    }
    return 0;
}