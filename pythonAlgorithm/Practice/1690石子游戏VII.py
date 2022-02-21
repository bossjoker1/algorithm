class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        n = len(stones)
        # dp[i][j]表示区间内的最大差值
        dp = [[0]* n for _ in range(n)]
        presum = [0]*(n+1)
        for i in range(n):
            presum[i+1] = presum[i] + stones[i]

        for i in range(n-2, -1, -1):
            for j in range(i+1, n):
                # 当前先手去掉左边或者右边，则dp[i+1][j]或者dp[i][j-1]为对手先手取得的
                # 先手必然最大
                dp[i][j] = max(presum[j+1] - presum[i+1] - dp[i+1][j], presum[j] - presum[i] - dp[i][j-1])

        return dp[0][n-1]