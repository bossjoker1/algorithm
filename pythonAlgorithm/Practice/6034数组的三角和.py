class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        temp = []
        for i in range(n):
            if i + 1 < n:
                temp.append((nums[i] + nums[i+1])%10)
                
        return self.triangularSum(temp)