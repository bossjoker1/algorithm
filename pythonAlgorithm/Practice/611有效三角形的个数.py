# 双指针 + 二分查找
# O(n^2log(n))能过

class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return 0
        nums.sort()
        res = 0
        for i in range(n):
            for j in range(i+1, n-1):
                res += bisect_left(nums[j+1:], nums[j] + nums[i])                

        return res