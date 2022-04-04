# 简单矩阵dp
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)

        dp = [[1e5] * (n) for _ in range(n)]

        for i in range(n):
            dp[0][i] = matrix[0][i]

        for i in range(1, n):
            for j in range(n):
                a = dp[i-1][j-1] if j>0 else 1e5
                b = dp[i-1][j]
                c = dp[i-1][j+1] if j<n-1 else 1e5
                dp[i][j] = min(a, b, c) + matrix[i][j]

        return min(dp[n-1])