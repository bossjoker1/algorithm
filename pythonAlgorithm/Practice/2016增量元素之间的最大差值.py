# 水题
class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        res, lmin = -1, nums[0]
        for i in range(1, len(nums)):
            if lmin >= nums[i]:
                lmin = nums[i]
            else:
                res = max(nums[i] - lmin, res)

        return res

            
