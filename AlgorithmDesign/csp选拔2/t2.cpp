#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAXN 105

typedef long long ll;
 
inline ll max(ll x,ll y){return x>y?x:y;}
 
inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

ll n, g[105][105];

int check(int x, int y){
    int len = 0, cnt = 0;
    for(int j = y; j <= n; j++){
        if (g[x][j] == 49){
            len = j - y + 1;
            cnt ++;
        }
    }
    if(cnt == 1) return 1;
    if(cnt != len) return 4;

    if (g[x+1][y] == 48 && g[x+cnt][y+cnt-1] == 48) return 2;
    if (g[x+1][y] == 48 && g[x+cnt][y] == 48 && g[x+cnt-1][y+1] == 49) return 3;
    if (g[x+cnt][y] == 48 && g[x+1][y+cnt-1] == 48) return 5;
    if (g[x+cnt][y] == 49 && g[x+1][y+cnt-1] == 48) return 6;
    if (g[x+cnt][y] == 48 && g[x+1][y] == 48) return 7;
    if (g[x+cnt][y] == 49 && g[x+cnt-1][y+1] == 49) return 8;
    if (g[x+cnt][y] == 48 && g[x+cnt-1][y+1] == 49) return 9;
    return 0;
}

int main(){
    n = read();
    rep(i, 1, n){
        rep(j, 1, n+1){
            g[i][j] = cin.get();
            if (j==n+1){
                g[i][j+1] = 0;
            }
        }
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            if (g[i][j] == 49) {
                printf("%d\n", check(i, j));
                return 0;
            }
        }
    }

    return 0;
}