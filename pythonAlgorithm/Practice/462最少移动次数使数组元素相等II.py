# 数学 排序

# 用到了前缀和

class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        nums.sort()
        s = sum(nums)
        minx = math.inf
        ts = 0
        for i in range(n):
            cur = abs(ts - nums[i]*i) + (s - nums[i] - ts) - nums[i] * ( n - i - 1)
            minx = min(minx, cur)
            ts += nums[i]

        return minx
