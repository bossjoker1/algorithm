# 想的有点复杂
# 看了下大佬们的题解，思路居然是一样的...
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        
        dp , dp2 = [[0, 0] for _ in range(100005)], [[0, 0] for _ in range(100005)]
        cnt1, cnt2 = 0, 0
        for i in range(n):
            if i % 2 == 0:
                dp[nums[i]][0] += 1
                dp[nums[i]][1] = nums[i]
                cnt1 += 1
            else:
                dp2[nums[i]][0] += 1
                dp2[nums[i]][1] = nums[i]
                cnt2 += 1      
        dp.sort(key=lambda x: -x[0])
        dp2.sort(key=lambda x: -x[0])
        if dp[0][1] != dp2[0][1]:
            return cnt1 - dp[0][0] + cnt2 - dp2[0][0]
        else:
            if cnt1 - dp[0][0] <= cnt2 - dp2[0][0]:
                if len(dp2) > 1:
                    return cnt1 - dp[0][0] + cnt2 - dp2[1][0]
                else:
                    return cnt1 - dp[0][0] + cnt2
            else:
                if len(dp) > 1:
                    return cnt1 - dp[1][0] + cnt2 - dp2[0][0]
                else:
                    return cnt2 - dp2[0][0] + cnt1