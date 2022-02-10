# 转化为打家劫舍问题
# 点数就是价值

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        dp = [0]*10001
        for item in nums:
            dp[item] += item
        l, r = min(nums), max(nums)
        f, s = dp[l], max(dp[l], dp[l+1])
        for i in range(l+2, r+1):
            f, s = s, max(s, f + dp[i])

        return s
