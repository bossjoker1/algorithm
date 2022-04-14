# 分段，左段有序 + 中段乱序 + 右段有序
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        maxn, minn = nums[0], nums[-1]
        left, right = 0, -1

        for i in range(n):
            if maxn > nums[i]:
                right = i
            else:
                maxn = nums[i]

            if minn < nums[n - i- 1]:
                left = n - i - 1
            else:
                minn = nums[n - i - 1]

        return right - left + 1