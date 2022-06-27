class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        m = len(grid)

        for i in range(m):
            for j in range(m):
                if (i == j or i + j == m - 1):
                    if grid[i][j] == 0:
                        return False
                else:
                    if grid[i][j] != 0:
                        return False

        return True
