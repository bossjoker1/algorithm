class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        ROW, COL = len(grid), len(grid[0])
        crow = [0] * ROW
        ccol = [0] * COL
        for i in range(ROW):
            for j in range(COL):
                if grid[i][j]:
                    crow[i] += 1
                    ccol[j] += 1
 
        res = 0
        for i in range(ROW):
            for j in range(COL):
                if crow[i] > 1 or ccol[j] > 1:
                    res += grid[i][j]
        return res