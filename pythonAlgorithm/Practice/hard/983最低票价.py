class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        # dp[i]表示第i天旅行(且完成了前面的旅行任务)所需要的最小花费
        n = days[-1]
        dp = [0] * (n+1)
        for i in range(len(days)):
            dp[days[i]] = -1
        for i in range(1, n+1):
            if not dp[i]:
                dp[i] = dp[i-1]
            else:
                a = dp[i-1] + costs[0] # 买当天的
                b = dp[i-7] + costs[1] if i-7>=0 else costs[1]
                c = dp[i-30] + costs[2] if i-30>=0 else costs[2]
                dp[i] = min(a, b, c)

        return dp[n]