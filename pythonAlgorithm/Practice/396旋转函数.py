# 推出通项公式降到O(n)
class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        n, s = len(nums), sum(nums)
        f0 = 0
        for i in range(n):
            f0 += i * nums[i]
        maxv  = f0
        for i in range(1, n):
            maxv = max(maxv, s + f0 - n*nums[n-i])
            f0 = s + f0 - n*nums[n-i]

        return maxv