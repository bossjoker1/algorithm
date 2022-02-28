# 区间dp？可我只会套模板
# 动规方程确实难想
# 想到了确实牛

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        # dp[i][j]表示(i, j)开区间内戳破所有气球获得最大硬币数
        dp = [[0] * (n + 2) for _ in range(n + 2)]
        val = [1] + nums + [1]
        
        # 为什么逆序？
        # A:父问题的求解一定要在子问题之前
        # 三层循环：左边界，右边界，分割点
        for i in range(n - 1, -1, -1):
            for j in range(i + 2, n + 2):
                for k in range(i + 1, j):
                    dp[i][j] = max(dp[i][j], val[i] * val[k] * val[j] + dp[i][k] + dp[k][j])
        
        return dp[0][n + 1]