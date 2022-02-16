# 不需要动态规划
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n, res = len(nums), 0
        if n < 3:
            return 0
        left, d = 0, sys.maxsize
        for i in range(1, n):
            td = nums[i] - nums[i-1]
            if td != d:
                d = td
                left = i - 1
            else:
                res += i - left - 1

        return res