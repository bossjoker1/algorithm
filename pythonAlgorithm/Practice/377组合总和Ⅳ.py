# 进阶：如果nums中有负数，则会导致队列无限长
# 所以还得限制结果队列的长度才能做
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        # dp[i]表示和为i时的组合个数
        dp = [0] * (target + 1)
        dp[0] = 1
        nums.sort()

        for i in range(1, target+1):
            for item in nums:
                if i - item < 0:
                    break
                dp[i] += dp[i - item]

        return dp[target]