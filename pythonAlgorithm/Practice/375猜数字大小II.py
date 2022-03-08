class Solution:
    def getMoneyAmount(self, n: int) -> int:
        # dp[i][j]表示在数字i ~ j里面选所需要花费的最小值
        # i~j里面枚举k，花费k，分割成两个区间，因为要保证猜对的，所以得去大的区间
        # 然后在所有k中选取最少花费的选择
        # dp[i][j] = min(dp[i][j], k + max(dp[i][k-1], dp[k+1][j]))

        dp = [[0] * (n+1) for _ in range(n+1)]

        for i in range(n, 0, -1):
            for j in range(i+1, n+1):
                dp[i][j] = n * n 
                for k in range(i, j):
                    dp[i][j] =  min(dp[i][j], k + max(dp[i][k-1], dp[k+1][j]))

        return dp[1][n]