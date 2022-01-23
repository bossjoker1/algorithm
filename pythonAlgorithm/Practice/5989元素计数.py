# 水题
class Solution:
    def countElements(self, nums: List[int]) -> int:
        nums.sort()
        
        i = 0
        while i < len(nums):
            if nums[i] != nums[0]:
                break
            else:
                i += 1
        i2 = 0
        while i2 < len(nums):
            if nums[len(nums) - 1 - i2] != nums[len(nums)-1]:
                break
            else:
                i2 += 1
                
        if i == len(nums) or i2 == len(nums):
            return 0
        
        return len(nums) - i - i2
                
            
            