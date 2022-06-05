class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        n = len(nums)
        
        while n > 1:
            newNum = [0] * (n//2)
            for i in range(n//2 - 1):
                if i % 2 == 0:
                    newNum[i] = min(nums[2 * i], nums[2 * i + 1])
                else:
                    newNum[i] = max(nums[2 * i], nums[2 * i + 1])
                    
            n = len(newNum)
            nums = newNum.copy()
            
        return nums[0]
        