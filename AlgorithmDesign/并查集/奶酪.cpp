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

int par[MAX_N], h[MAX_N];
 
typedef long long ll;
 
inline ll max(ll x,ll y){return x>y?x:y;}
 
inline ll read(){
    ll x=0,f=1;char ch=' ';
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

bool CanJoin(ll x, ll y, ll z, ll x1, ll y1, ll z1, ll r){
    ll sum = (x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1);
    ll r2 = 4*r*r;
    return sum <= r2;
}


ll n, ball[MAX_N][3];

int main(){
    ll T = read();
    rep(i, 1, T){
        n = read();
        init(n+2);
        // memset(ball, 0, sizeof(ball));
        ll h = read(), r = read();
        ll x, y, z;
        rep(i, 1, n){
            x = read(), y = read(), z = read();
            ball[i][0] = x, ball[i][1] = y, ball[i][2] = z;
            if(z+r>=h) {
                unite(i, n+2); 
                // printf("get top\n");
            } // 与上表面合并
            if(z-r<=0) {
                unite(i, n+1);
                // printf("get bottom\n");
            }// 与下表面合并

            // 遍历&合并
            rep(j, 1, i-1){
                if(CanJoin(x, y, z, ball[j][0], ball[j][1], ball[j][2], r)){
                    unite(i, j);
                    // printf("unite %d %d\n", i, j);
                }
            }
        }

        if(same(n+1, n+2)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}