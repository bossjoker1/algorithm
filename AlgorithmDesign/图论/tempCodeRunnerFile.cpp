// 尼玛 我的prim算法 bug找不出来
// 被迫 kruskal
#include<bits/stdc++.h>
using namespace std;

 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAXN 90005
 
typedef long long ll;
 
inline ll max(ll x,ll y){return x>y?x:y;}
 
inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}


edge es[MAXN];
int par[4005];
int h[4005];
int n, m, k, cnt;

struct edge { ll u, v, cost;};

bool comp(const edge&e1, const edge&e2){
    return e1.cost < e2.cost || e1.cost == k;
}


//初始化
inline void init(int n){
    for(int i = 1 ;i <= n; i++){
        par[i] = i;
        h[i] = 0;
    }
}

//查询树根
int find(int x){
    if (par[x] == x)
        return x;
    else
        //递归查找，同时压缩路径
        return par[x] = find(par[x]);
}

//合并 x 和 y 所属的集合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) return;

    if(h[x] < h[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(h[x] == h[y]) h[x]++; 
    }
}  

bool same(int x, int y){
    return find(x) == find(y);
}


ll krustral(){
    //并查集初始化
    ll res = 0;
    for(int i = 1; i <= cnt; i++){
        edge e = es[i];
        if(!same(e.u, e.v) || e.cost == k){
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

 
int main(){
    n = read(), m = read(), k = read();
    init(n);
    // 读坐标
    rep(i, 1, m){
        es[++cnt].u = read(), es[cnt].v = read(), es[cnt].cost = read();
    }
    sort(es+1, es+cnt+1, comp);
    printf("%lld\n", krustral());

    return 0;
}