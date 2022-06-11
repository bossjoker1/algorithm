# 子序列 回文
# dp
class Solution:
    def countPalindromicSubsequences(self, s: str) -> int:
        MOD = 10 ** 9 + 7
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = 1

        for sz in range(2, n + 1):
            for j in range(sz - 1, n):
                i = j - sz + 1
                if s[i] == s[j]:
                    low, high = i + 1, j - 1
                    while low <= high and s[low] != s[i]:
                        low += 1
                    while high >= low and s[high] != s[j]:
                        high -= 1
                    if low > high:
                        dp[i][j] = (2 + dp[i + 1][j - 1] * 2) % MOD
                    elif low == high:
                        dp[i][j] = (1 + dp[i + 1][j - 1] * 2) % MOD
                    else:
                        dp[i][j] = (dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1]) % MOD
                else:
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]) % MOD
        return dp[0][n - 1]


