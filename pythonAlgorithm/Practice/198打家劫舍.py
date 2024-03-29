# 对每一个，偷或不偷
# 偷的话就是i-2转移过来 + nums[i]
# 不偷就是i-1转移过来且不加本身的值

class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0

        size = len(nums)
        if size == 1:
            return nums[0]
        
        first, second = nums[0], max(nums[0], nums[1])
        for i in range(2, size):
            first, second = second, max(first + nums[i], second)
        
        return second

