# 肯定只能限制在O(logn)的复杂度
# 一部分是有序的，一部分是无序的
# 旋转的右边大的部分全部到左边去了，因此左边块都比右边块大
# 找到有序的，通过二分思路判断是否在该有序部分，或者在无序部分
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        l, r = 0, len(nums) - 1
        while l <= r:
            mid =  l + r >> 1
            if nums[mid] == target:
                return mid
            # 说明左边有序
            if nums[l] <= nums[mid]:
                if nums[0] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                # 说明右边有序
                if nums[mid] < target <= nums[len(nums) - 1]:
                    l = mid + 1
                else:
                    r = mid - 1
        return -1