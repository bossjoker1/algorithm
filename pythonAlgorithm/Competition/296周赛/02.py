class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        
        nums.sort()
        
        res = 0
        
        pre = -1
        
        for i in range(n):
            if pre == -1 or nums[i] - pre > k:
                res += 1
                pre = nums[i]
            
        return res