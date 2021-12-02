#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

const int maxn = 65536+5; // 2^16
const int maxc = 76 + 5;  // 1+(16-1)*5

inline int max(int x, int y) { return x > y ? x : y; }

inline int read() {
    int x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

//dp[i][j] 抽卡状态为i，抽卡次数为j时的概率
double P[20], dp[maxn][maxc] = {0};

int n, k;

int getCardNum(int mask){
    int cnt = 0;
    rep(i, 0, n-1){
        if((mask>>i)&1) cnt++;
    }
    return cnt;
}


int main(){
    // 加快cin,cout效率
    ios_base::sync_with_stdio(false);
    n = read(),  k = read();
    rep(i, 0, n-1) scanf("%lf", &P[i]);
    // count为实际最大抽取次数，即抽了一次后之后都为硬币
    int mask = 1<<n, count = 1+(n-1)*k; 

    dp[0][0] = 1;

    double ans = 0;

    rep(s, 0, mask-1){
        rep(j, 0, count){
            int cnt = getCardNum(s);
            // 抽取总次数 - 抽到的卡种类 = 硬币数量
            if(cnt + (j-cnt)/k >= n){
                ans += dp[s][j] * j;
                continue;
            }

            rep(i, 0, n-1){
                // 已有x卡，可以从之前有x卡再抽取一张x卡转移
                // 没有x卡，可以从没有x卡抽取一张x卡转移
                dp[s|(1<<i)][j+1] += dp[s][j] * P[i];
            }
        }
    }

    printf("%.10lf\n", ans);

    return 0;
}