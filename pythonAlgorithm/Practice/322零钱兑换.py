# dp[i]表示金额为i需要凑的最小硬币数
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [amount + 1] * (amount+1)
        dp[0] = 0
        for i in range(amount+1):
            for coin in coins:
                if i - coin >= 0:
                    dp[i]  = min(dp[i-coin]+1, dp[i])

        return dp[amount] if dp[amount] != amount+1 else -1