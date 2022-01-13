# 没什么意思
# 有些情况我们只能将当前二分区间的左边界加一，右边界减一，然后在新区间上继续二分查找
# 最坏O(n)，只能说没什么大的意义
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if not nums:
            return False
        
        n = len(nums)
        if n == 1:
            return nums[0] == target
        
        l, r = 0, n - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return True
            # 重复元素导致无法判断哪个区间有序，减去了再看
            # 不用担心丢掉了某个元素
            if nums[l] == nums[mid] and nums[mid] == nums[r]:
                l += 1
                r -= 1
            elif nums[l] <= nums[mid]:
                if nums[l] <= target and target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] < target and target <= nums[n - 1]:
                    l = mid + 1
                else:
                    r = mid - 1
        
        return False

