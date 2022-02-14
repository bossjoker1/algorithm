# 找到单一元素对成对元素下标奇偶性的影响
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n - 1
        while l < r:
            mid = l + r >> 1
            if mid % 2 == 0:
                if mid + 1 < n and nums[mid] == nums[mid + 1]:
                    l = mid + 1
                else:
                    r = mid
            else:
                if mid - 1 >= 0 and nums[mid] == nums[mid - 1]:
                    l = mid + 1
                else:
                    r = mid

        return nums[r]
    
# 由异或优化可得
# 学到了
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n - 1
        while l < r:
            mid = l + r >> 1
            if nums[mid] == nums[mid ^ 1] :
                l = mid + 1
            else:
                r = mid
        return nums[r]