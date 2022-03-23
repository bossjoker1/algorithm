# 简单dp
MOD = int(1e9+7)
class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        # dp[i][j]表示有i个骰子掷到j的方式数量
        # dp[i][j] = dp[i-1][j-z] 1<=z<=k

        dp = [[0] * (target+1) for _ in range(n+1)]

        for i in range(1, min(k, target) + 1):
            dp[1][i] = 1

        for i in range(2, n+1):
            for j in range(target+1):
                for z in range(j-1, max(0, j-k-1), -1):
                    dp[i][j] += dp[i-1][z] % MOD


        return dp[n][target] % MOD