class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        res = 0
        n = len(grid)

        for i in range(n):
            maxCol, maxRow = 0, 0
            for j in range(n):
                # 俯视图，只要有就行
                if grid[i][j]:
                    res += 1
                maxCol = max(maxCol, grid[i][j])
                maxRow = max(maxRow, grid[j][i])

            res += maxCol + maxRow

        return res 
