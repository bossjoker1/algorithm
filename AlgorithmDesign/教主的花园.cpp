#include <stdio.h>
#include <string.h>

#define rep(i,l,r) for(int i=(l);i<=(r);++i)

typedef long long ll;

// 状态越少维数越高，方便理解
// 3表三种树，2表当前树往后是准备上升还是下降

ll dp[100005][3][2], vals[100005][3];

inline ll max(ll x,ll y){return x>y?x:y;}

inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

int main() {
    int n;
    scanf("%d",&n);

    // 0 1 2 保存10 20 30高度的树在第i个位置的价值
    rep(i, 1, n){
        vals[i][0] = read();
        vals[i][1] = read();
        vals[i][2] = read();
    }

    ll max_val = -1;

    // 必须要枚举第一个，不能单独处理，因为其影响两个状态
    rep(j, 0, 2){

        rep(i, 0, 2)
            rep(k, 0, 1)
                dp[1][i][k] = 0;

        dp[1][j][0] = dp[1][j][1] = vals[1][j];

        rep(i, 2, n){    
            dp[i][0][0] = vals[i][0] + max(dp[i-1][1][1], dp[i-1][2][1]);
            dp[i][1][0] = vals[i][1] + dp[i-1][2][1];
            dp[i][1][1] = vals[i][1] + dp[i-1][0][0];
            dp[i][2][1] = vals[i][2] + max(dp[i-1][0][0], dp[i-1][1][0]);
        }

        for(int i=0;i<j;++i)
            max_val = max(max_val, dp[n][i][0]);
        for(int i=j+1;i<3;++i)
            max_val = max(max_val, dp[n][i][1]);
    }

    printf("%lld\n", max_val);

    return 0;
}