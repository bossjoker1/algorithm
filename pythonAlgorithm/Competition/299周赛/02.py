# 简单dp
# 可以简化为f[i]
MOD = int(1e9+7)
class Solution:
    def countHousePlacements(self, n: int) -> int:
        # dp[i][0] 表示前 i 块放置房子的总情况数，0表示第i块不放，1表示第i块放
        dp = [[0] * 2  for _ in range(n+1)]

        dp[1][0] = dp[1][1] = 1

        for i in range(2, n+1):
            dp[i][1] = dp[i-1][0] % MOD
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD

        return (dp[n][1] + dp[n][0]) * (dp[n][1] + dp[n][0]) % MOD