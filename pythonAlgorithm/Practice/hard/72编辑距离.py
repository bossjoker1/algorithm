# hard
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)

        dp = [[0]*(n+1) for _ in range(m+1)]

        # dp[i][j]还是表示word1的前i个字母转换成word2的前j个字母所使用的最少操作

        # basecase
        for i in range(m+1):
            dp[i][0] = i
        for j in range(n+1):
            dp[0][j] = j

        for i in range(1, m+1):
            for j in range(1, n+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    # 取最小值，依次为增、删、插入
                    dp[i][j] = 1 + min(dp[i][j-1] , dp[i-1][j] , dp[i-1][j-1])

        return dp[m][n]
