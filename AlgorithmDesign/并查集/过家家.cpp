// 测试样例没问题
// 但是oj怎么奇怪，wa样例还会变？
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAX_N 255

int par[MAX_N], n;

bool visit[MAX_N][MAX_N]; // 访问数组
 
inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

//初始化
inline void init(int n){
    for(int i = 1 ;i <= n; i++){
        par[i] = i;
    }
}

//查询树根
inline int find(int x){
    if (par[x] == x)
        return x;
    else
        //递归查找，同时压缩路径
        return par[x] = find(par[x]);
}

//合并 x 和 y 所属的集合
inline void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[x] = par[y];
}

inline void add(int u){
    rep(i, 1, n){
        if(visit[u][i]){
            visit[find(u)][i] = true; // 归结到集合的根节点
        }
    }
}


int main(){
    n = read();
    int m = read(), k = read(), f = read(), ans;
    init(n);
    rep(i, 1, m){
        int x = read(), y = read();
        visit[x][y] = true;
    }
    // 朋友关系并成集合
    rep(i, 1, f){
        unite(read(), read());
    }
    // 归结到每个集合的根节点
    rep(i, 1, n){
        add(i);
    }

    rep(i, 1, n){
        // 对根节点所能接收的男生遍历
        if(par[i] == i){
            int res = 0;
            rep(j, 1, n){
                if(visit[i][j]){
                    res++;
                }
            }
            ans = min(ans, res);
        }
    }
    ans = min(ans+k, n);
    printf("%d\n", ans);
    return 0;
}