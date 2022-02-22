# dp[i]表示前i个石头先手能不能赢
# 如果i是平方数，显示先手必赢
# 如果dp[i - j*j]必输，那么此时先手也必赢

class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        sq, dp = sqrt(n), [False] * (n+1)
        for i in range(0, n+1):
            if not dp[i]:
                for j in range(1, int(sq) + 1):
                    if i + j*j <= n:
                        dp[i + j*j] = True

        return dp[n]