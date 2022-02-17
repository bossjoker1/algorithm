# 想的有点复杂
# 看了下大佬们的题解，思路居然是一样的...
# 绷不住了，居然还改了样例
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
            min1 =  min2 = maxsize
            if len(dp2) > 1:
                min1 = min(min1, cnt1 - dp[0][0] + cnt2 - dp2[1][0])
            min1 = min(min1, cnt1 - dp[0][0] + cnt2)
            if len(dp) > 1:
                min2 = min(min2, cnt1 - dp[1][0] + cnt2 - dp2[0][0])
            min2 = min(min2, cnt2 - dp2[0][0] + cnt1)

        return min(min1, min2)