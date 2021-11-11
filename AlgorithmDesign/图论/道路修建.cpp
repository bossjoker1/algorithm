// 尼玛 我的prim算法 bug找不出来
// 被迫 kruskal
#include<bits/stdc++.h>
using namespace std;

 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAXN 1000005
 
typedef long long ll;
 
inline ll max(ll x,ll y){return x>y?x:y;}
 
inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

struct edge { ll u, v; double cost;};

ll axis[MAXN][2];

bool comp(const edge&e1, const edge&e2){
    return e1.cost < e2.cost;
}

edge es[MAXN];
int par[MAXN];
int h[MAXN];
int n, m, cnt;

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


double krustral(){
    //并查集初始化
    double res = 0.0;
    for(int i = 1; i <= cnt; i++){
        edge e = es[i];
        if(!same(e.u, e.v)){
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

 
int main(){
    n = read(), m = read();
    init(n);
    // 读坐标
    rep(i, 1, n){
        axis[i][0] = read(), axis[i][1] = read();
    }

    rep(i, 1, m){
        unite(read(), read());
    }

    rep(i, 1, n-1){
        rep(j, i+1, n){
            double w = sqrt((axis[i][0] - axis[j][0])*(axis[i][0] - axis[j][0]) + (axis[i][1] - axis[j][1])*(axis[i][1] - axis[j][1]));
            es[++cnt].u = i, es[cnt].v = j, es[cnt].cost = w; 
        }
    }
    sort(es+1, es+cnt+1, comp);
    printf("%.2f\n", krustral());

    return 0;
}