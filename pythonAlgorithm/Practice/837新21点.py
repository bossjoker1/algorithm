# dp[i]表示从i分开始赢的概率即≥k 不大于n
# 我用dp[i]表示分数为i的种数求的不对
class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0:
            return 1.0
        dp = [0.0] * (k + maxPts)
        for i in range(k, min(n, k + maxPts - 1) + 1):
            dp[i] = 1.0
        dp[k - 1] = float(min(n - k + 1, maxPts)) / maxPts
        for i in range(k - 2, -1, -1):
            dp[i] = dp[i + 1] - (dp[i + maxPts + 1] - dp[i + 1]) / maxPts
        return dp[0]
