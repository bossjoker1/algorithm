#include <stdio.h>
#include <string.h>

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAXN  1001

typedef long long ll;

inline ll max(ll x,ll y){return x>y?x:y;}

inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

// 这题虽然说是可以不同时出发，但是由于卡路里都是正值，所以两个人同时走，同时到，和就最大



// 碰面点为中间任意一点，从四个角向该点进行dp
ll path[MAXN][MAXN], dp1[MAXN][MAXN], dp2[MAXN][MAXN], dp3[MAXN][MAXN], dp4[MAXN][MAXN];

int main(){
    int n, m;
    n = read(), m = read();

    rep(i, 1, n)
        rep(j, 1, m)
            path[i][j] = read();

        // 计算以四个角为起点的四个 DP
    rep(i, 1, n)
        rep(j, 1, m) 
            dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + path[i][j];
        
    rep(i, 1, n)
        rpe(j, m, 1) 
            dp2[i][j] = max(dp2[i-1][j], dp2[i][j+1]) + path[i][j];

    rpe(i, n, 1)
        rep(j, 1, m) 
            dp3[i][j] = max(dp3[i+1][j], dp3[i][j-1]) + path[i][j];
        
    rpe(i, n, 1)
        rpe(j, m, 1)
            dp4[i][j] = max(dp4[i][j+1], dp4[i+1][j]) + path[i][j];

    ll ans = 0;
    rep(i, 2, n-1) {
        rep(j, 2, m-1) {
            // 碰面时对四角汇合的两种情况
            
            //         左上角
            //    左下角 汇合 右上角
            //         右下角

            //         右上角
            //    左上角 汇合 右下角
            //         左下角
            ans = max(ans, dp1[i-1][j]+dp2[i][j+1]+dp3[i][j-1]+dp4[i+1][j]);
            ans = max(ans, dp1[i][j-1]+dp2[i-1][j]+dp3[i+1][j]+dp4[i][j+1]);
        }
    }
    
    printf("%lld\n", ans);

    return 0;
}