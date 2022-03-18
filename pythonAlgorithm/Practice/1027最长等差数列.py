# dp[i][d]表示以nums[i]为结尾，d为公差的序列长度
# 将负公差加上一定值转为正数
# 枚举 0 ~ i-1 

class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[1] * 1001 for _ in range(n+1)]    
        ans = 0
        for i in range(n):
            for j in range(i):
                d = nums[i] - nums[j] + 500
                dp[i][d] = max(dp[i][d], dp[j][d] + 1)
                ans = max(ans, dp[i][d])

        return ans
