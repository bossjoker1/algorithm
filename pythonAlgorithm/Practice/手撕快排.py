# 随机pivot快速排序
import random


class Solution:
    def sortArray(self, nums):
        n = len(nums)
        def QuickSort(left, right):
            if left >= right: return nums
            index = random.randint(left, right)
            pivot = nums[index]
            nums[index], nums[left] = nums[left], nums[index]
            i, j = left, right
            while i < j:
                while i < j and nums[j] > pivot:
                    j -= 1
                nums[i] = nums[j]
                while i < j and nums[i] <= pivot:
                    i += 1
                nums[j] = nums[i]
            nums[i] = pivot
            QuickSort(left, i-1)
            QuickSort(i+1, right)
            return nums
            
        return QuickSort(0, n-1)

nums = [7,5,9,10,123,2,1,78,54,23,67,21,7,9,23]
c = Solution()
print(c.sortArray(nums))