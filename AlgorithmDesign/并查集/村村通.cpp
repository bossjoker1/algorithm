// 跟修复公路几乎一样
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

#define MAX_N 1005

int par[MAX_N];
int h[MAX_N];
 
 
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
    int n = 1 , m;
    while(1){
        n = read(), m = read();
        if(n == 0) break;
        init(n);
        int cnt = n;
        int x, y, px, py;
        rep(i, 1, m){
            x = read(), y = read();
            px = find(x), py = find(y);
            if(px!=py){
                par[px] = par[py];
                cnt--;
            }
        }
        printf("%d\n", --cnt);
    }

    return 0;

}