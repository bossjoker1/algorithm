# 背包问题，考虑些边界条件，但是时间复杂度为O(n*k*max(piles))
# 超时
class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        n = len(piles)
        # guess:背包问题
        # dp[i][j]表示前i件物品放进容量为j能获得的最大价值
        # dp[i][j] = max(dp[i-1][j](不放i), dp[i-1][j-a] + sum(val[:a])) 1<=a<=min(len_i, k)
        dp = [ [0] * (k+1) for _ in range(n+1)]

        for i in range(1, n+1):
            for j in range(1, k+1):
                temp = 0
                for a in range(1, min(len(piles[i-1]), j)+1):
                    temp = max(temp, dp[i-1][j-a] + sum(piles[i-1][:a]))
                dp[i][j] = max(dp[i-1][j], temp)
        # print(dp)
        return dp[n][k]

# 优化思路：空间=>压成一维，注意逆序遍历
#          时间=>开始为当前stack的长度

class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        f = [0] * (k + 1)
        sum_n = 0
        for pile in piles:
            n = len(pile)
            for i in range(1, n):
                pile[i] += pile[i - 1]  # pile 前缀和
            sum_n = min(sum_n + n, k)  # 优化：j 从前 i 个栈的大小之和开始枚举（不超过 k）
            for j in range(sum_n, 0, -1):
                f[j] = max(f[j], max(f[j - w - 1] + pile[w] for w in range(min(n, j))))  # w 从 0 开始，物品体积为 w+1
        return f[k]