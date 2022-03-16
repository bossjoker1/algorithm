# 要求O(logn)，标签提示二分查找
# "二段性"可真不好理解
# 因为本题左右边界视为-∞，所以mid点可以看是上坡还是下坡
# 上坡说明右边存在山峰，下坡说明左边存在山峰
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] > nums[mid + 1]:
                r = mid
            else:
                l = mid + 1

        return l