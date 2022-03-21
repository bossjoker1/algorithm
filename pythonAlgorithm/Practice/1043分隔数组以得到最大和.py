class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        
        # dp[i]表示arr[:i]按要求划分能得到的最大值
        # dp[i] = max (dp[i], dp[i-j] + max(arr[i-j:j+1]) * j)
        
        dp = [0]* (n+1)

        for i in range(1, n+1):
            maxn = -1
            for j in range(i-1, max(0, i-k) - 1, -1):
                maxn = max(arr[j], maxn)
                dp[i] = max(dp[i], dp[j] + maxn * (i-j))

        return dp[n]
    