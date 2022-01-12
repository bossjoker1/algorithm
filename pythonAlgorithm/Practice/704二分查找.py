# 练练手
# easy
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)
        while left < right:
            mid = left + right >> 1
            if nums[mid] == target:
                return mid
            elif target < nums[mid]:
                right = mid
            elif target > nums[mid]:
                left = mid + 1
        return -1