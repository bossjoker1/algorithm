# 维护每行每列的最大值即可
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)

        col, row = [0] * n, [0]*n

        for i in range(n):
            for j in range(n):
                col[i] = max(col[i], grid[i][j])
                row[i] = max(row[i], grid[j][i])
        res = 0
        for i in range(n):
            for j in range(n):
                res += min(col[i], row[j]) - grid[i][j]

        return res