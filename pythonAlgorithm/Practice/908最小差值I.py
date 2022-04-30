# 水题easy
class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        minv, maxv = min(nums), max(nums)

        if minv + k >= maxv - k:
            return 0
        else:
            return maxv - k - minv - k