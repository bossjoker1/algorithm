# 动规方程只实现了一半呜呜呜
# 我以为我要做出来了

MOD = int(1e9) + 7
class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        # dp[n][k] - dp[n][k-1] = dp[n-1][k] - dp[n-1][k-n] if k >= n else dp[n-1][k]
        dp = [1] + [0] * k
        for i in range(2, n + 1):
            next_dp = [1] + [0] * k
            for j in range(1, k + 1):
                next_dp[j] = (next_dp[j-1] + dp[j] - (dp[j-i] if j >= i else 0)) % MOD
            dp = next_dp
        return dp[-1] 