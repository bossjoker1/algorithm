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

#define MAX_N 1002
#define MAX_M 100005

struct edge
{
    int x, y, t;
}edges[MAX_M];

int operator < (const edge e1, const edge e2){
    return e1.t < e2.t;
}

int par[MAX_N];
 
inline int max(int x,int y){return x>y?x:y;}
 
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
int find(int x){
    if (par[x] == x)
        return x;
    else
        //递归查找，同时压缩路径
        return par[x] = find(par[x]);
}

int main(){
    int n = read(), m = read();
    init(n);
    int cnt = n;
    rep(i, 0, m-1){
        edges[i].x = read(), edges[i].y = read(), edges[i].t = read();
    }
    sort(edges, edges+m);

    rep(i, 0, m-1){
        int x = edges[i].x, y = edges[i].y;
        int px = find(x), py = find(y);
        if(px != py){
            par[px] = par[py];
            cnt--;
            if(cnt == 1){
                printf("%d\n", edges[i].t);
                return 0;
            }
        }
        
    }

    printf("-1\n");
    return 0;
}