# 能不能到达最后一个索引
# 贪心
# 遇到多的就及时补给

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 1: return True
        step = nums[0]
        for i in range(1, n):
            step -= 1
            if step < 0:
                return False
            if step < nums[i]:
                step = nums[i]
        
        if step >= 0:
            return True