# 最少的跳跃次数
# 维护此次跳跃范围内所能提供的最远的右界

class Solution:
    def jump(self, nums: List[int]) -> int:
        maxRight, step, end = 0, 0, 0

        for i in range(len(nums)-1):
            maxRight = max(maxRight, i + nums[i])
            if i == end:
                end = maxRight
                step += 1

        return step