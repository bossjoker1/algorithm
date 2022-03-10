# 区间dp

class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        # f[i][j]表示打印i~j字符串需要的最少步数
        # 求f[0][n-1]
        f = [[math.inf]*n for _ in range(n)]
        for i in range(n):
            f[i][i] = 1
        for d in range(2, n+1):
            for l in range(n-d+1):
                r = l + d - 1
                if s[l] == s[r]:
                    f[l][r] = min(f[l+1][r], f[l][r-1])
                else:
                    for k in range(l, r):
                        f[l][r] = min(f[l][r], f[l][k]+f[k+1][r])

        return f[0][n-1]


# class Solution {
# public:
#     int strangePrinter(string s) {
#         int n = s.size();
#         vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
#         for(int i = n-1; i >= 0; --i)
#         {
#             dp[i][i] = 1;
#             for(int j = i + 1; j < n; ++j)
#             {
#                 if(s[i] == s[j])
#                     dp[i][j] = dp[i][j-1];
#                 else //枚举区间内所有的可能性，取最优
#                     for(int k = i; k < j; ++k)
#                         dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
#             }
#         }
#         return dp[0][n-1];
#     }
# };
