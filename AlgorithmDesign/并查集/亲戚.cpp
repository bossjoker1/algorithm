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

#define MAX_N 5005

int par[MAX_N];
int h[MAX_N];
 
typedef long long ll;
 
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

int main(){
    int n = read(), m = read(), p = read();
    init(n);
    int t1,t2;
    rep(i, 1, m){
        t1 = read(), t2 = read();
        unite(t1, t2);
    }
    rep(i, 1, p){
        t1 = read(), t2 = read();
        if(same(t1, t2))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}