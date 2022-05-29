# 单调栈，但是怎么维护真没想出来
class Solution:
    def totalSteps(self, nums: List[int]) -> int:
        stack = []
        N = len(nums)
        ans = 0
        for i in range(N):
            t = 1
            while stack and nums[stack[-1][0]] <= nums[i]:
                _, pt = stack.pop()
                t = max(t, pt + 1)
            if stack:
                ans = max(ans, t)
            stack.append((i,t))
        return ans

