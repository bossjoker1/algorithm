class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        res = []

        for item in nums:
            if item % 2 == 0:
                res.append(item)

        for item in nums:
            if item % 2 != 0:
                res.append(item)

        return res
    
# 双指针 + 原地交换
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        left, right = 0, len(nums) - 1
        while left < right:
            while left < right and nums[left] % 2 == 0:
                left += 1
            while left < right and nums[right] % 2 == 1:
                right -= 1
            if left < right:
                # 此时left一定是奇数，而right一定是偶数了
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
        return nums

