# 不能用除法，O(n)
# 前缀积和后缀积..
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pre = [1] * (n+1)
        for i in range(1, n+1): 
            pre[i] = pre[i-1] * nums[i-1]
        post = [1] * (n+1)
        for i in range(n-2, -1, -1):
            post[i] = post[i+1] * nums[i+1]
        
        res = []

        for i in range(n):
            res.append(pre[i]*post[i])
        return res
    
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left, right = 1, 1
        n = len(nums)
        res = [0] * n
        for i in range(n):
            res[i] = left
            left *= nums[i]
        for i in range(n-1, -1, -1):
            res[i] *= right
            right *= nums[i]

        return res