# 学到了, n数之和tql

class Solution:
    def fourSum(self, nums: [int], target: int) -> [[int]]:
        #-----------------参考----编写n个数的和的API----------------------
        # 排序
        nums = sorted(nums)
        return self.nSum(nums, 4, 0, target)
    def nSum(self, nums: [int], n: int, start: int, target: int):
        out = []
        size = len(nums)
        if n < 2 and size < n: return out
        if n == 2: # 两数之和，采用双指针法
            left = start
            right = size - 1
            while left < right:
                left_value = nums[left]
                right_value = nums[right]
                total = left_value + right_value
                if total > target:
                    right -= 1
                    # 去重，指针左移
                    while (right_value == nums[right] and left < right): right -= 1
                elif total < target:
                    left += 1
                    # 去重，指针右移
                    while (left_value == nums[left] and left < right): left += 1
                else:
                    # 加入元素，同时去重
                    out.append([left_value, right_value])
                    while (right_value == nums[right] and left < right): right -= 1
                    while (left_value == nums[left] and left < right): left += 1
        else: # 大于2数之和，递归计算
            i = start
            while i < size:
                sub_out = self.nSum(nums, n-1, i+1, target-nums[i])
                for j in sub_out:
                    j.append(nums[i])
                    out.append(j)
                i += 1
                while i < size and nums[i] == nums[i-1]:
                    i += 1  #去重
        return out