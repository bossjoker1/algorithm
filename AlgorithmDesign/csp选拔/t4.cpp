#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

const int maxn = 2005;

typedef vector<int> vec;
typedef vector<vec> mat; // 矩阵 

inline int max(int x, int y) { return x > y ? x : y; }

inline int read() {
    int x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

int N, M, n, m;
int xdp[maxn][maxn], ydp[maxn][maxn], dp[maxn][maxn];
mat A(maxn, vec(maxn)), B(maxn, vec(maxn));

int main() {

    memset(xdp, 0, sizeof(xdp));
    memset(ydp, 0, sizeof(ydp));
    memset(dp, 0, sizeof(dp));

    N = read(), M = read();
    rep(i, 1, N) {
        rep(j, 1, M) {
            A[i][j] = read();
        }
    }
    n = read(), m = read();
    rep(i, 1, n) {
        rep(j, 1, m) {
            B[i][j] = read();
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            // 矩阵匹配
            bool flag = true;
            for (int k = 1; k <=  n && flag; k++) {
                for (int w = 1; w <= m; w++) {
                    if (A[k+i-1][w+j-1] != B[k][w] || k+i-1 > N || w+j-1 > M) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                xdp[i + n - 1][j + m - 1] = xdp[i + n - 1][j - 1] + 1;
                ydp[i + n - 1][j + m - 1] = ydp[i - 1][j + m - 1] + 1;
                if (xdp[i + n - 1][j - 1] && ydp[i - 1][j + m - 1])
                    dp[i + n - 1][j + m - 1] = max(dp[i + n - 1][j + m - 1], xdp[i + n - 1][j + m - 1] + ydp[i + n - 1][j + m - 1]);
                else
                    dp[i + n - 1][j + m - 1] = max(dp[i + n - 1][j + m - 1], xdp[i + n - 1][j + m - 1] + ydp[i + n - 1][j + m - 1] - 1);

            }
        }
    }

    int cnt = 0;
    rep(i, 1, N) {
        rep(j, 1, M) {
            cnt = cnt + dp[i][j];
        }
    }

    printf("%d\n", cnt);

    return 0;
}