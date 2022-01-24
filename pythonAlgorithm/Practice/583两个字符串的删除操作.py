# 转为求最长公共子序列问题
# dp[i][j]表示公共子序列长度

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[0]*(n+1) for _ in range(m+1)]

        for i in range(1, m+1):
            for j in range(1, n+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])


        return m + n - 2*dp[m][n]
    
# 更贴近题意
# 设dp[i][j]表示word1[0--i-1], word2[0--j-1]相同时需要删除的步数

# class Solution {
#     public int minDistance(String word1, String word2) {
#         int l1 = word1.length(), l2 = word2.length();
#         int[][] dp = new int[l1 + 1][l2 + 1];
#         for (int i = 0; i <= l1; i++) {
#             dp[i][0] = i;
#         }
#         for (int i = 0; i <= l2; i++) {
#             dp[0][i] = i;
#         }
#         for (int i = 1; i <= l1; i++) {
#             for (int j = 1; j <= l2; j++) {
#                 if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
#                     dp[i][j] = dp[i - 1][j - 1];
#                 } else {
#                     dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + 1;
#                 }
#             }
#         }
#         return dp[l1][l2];
#     }
# }