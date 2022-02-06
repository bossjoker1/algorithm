# 好题，感觉蛮多改编题型
# 找最右较小数，即a[i]<a[j] 得到a[p]
# 找最右边比a[p]大的数a[q]，用于交换
# 交换后[p+1, n)为降序，将该区间翻转

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p, p2, n  = -1, -1, len(nums)
        for i in range(n-2, -1, -1):
            if nums[i] < nums[i+1]:
                p = i
                break
        if p == -1:
            nums.sort()
            return

        for i in range(n):
            if nums[i] > nums[p]:
                p2 = i

        nums[p2], nums[p] = nums[p], nums[p2]
        p += 1
        while p < n-1:
                nums[p],nums[n-1] = nums[n-1], nums[p]
                p += 1
                n -= 1
                
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:
            j = len(nums) - 1
            while j >= 0 and nums[i] >= nums[j]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        
        left, right = i + 1, len(nums) - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1

