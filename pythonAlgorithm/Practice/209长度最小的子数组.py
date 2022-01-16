# 与862不同，这题全是正整数，即前缀和自然为递增

# 1.暴力枚举会超时O(n^2)


# O(n)
# 2.队列直接维护

# 略

# 3.将队列转化为+-
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l, res = 0, math.inf
        for r, v in enumerate(nums):
            target -= v
            while target <= 0:
                res = min(res, r + 1 - l)
                target += nums[l]
                l += 1
        return res if res != math.inf else 0

            
# 双指针，不过其实队列的思想也是双指针

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l, res = 0, math.inf
        s = 0
        i, j = 0, 0
        while i < len(nums):
            s += nums[i]
            while s - nums[j] >= target: 
                s -= nums[j]
                j += 1
            if s >= target:
                res = min(res, i - j + 1)
            i += 1
        return res if res != math.inf else 0

            




