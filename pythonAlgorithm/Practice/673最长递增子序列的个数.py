class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        maxl, res = 1, 0
        cnt = [1] * n
        dp = [1] * n

        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    if dp[i] < dp[j] + 1:
                        cnt[i] = cnt[j]
                        dp[i] = dp[j] + 1
                    elif dp[i] == dp[j] + 1:
                        cnt[i] += cnt[j]
            
            if maxl < dp[i]:
                maxl = dp[i]
                res = cnt[i]
            elif maxl == dp[i]:
                res += cnt[i]

        return res
        
                        