# 数据很小直接暴力回溯就行

class Solution:
    ret = 0 
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        def backTrack(i, j, gold):
            self.ret = max(self.ret, gold)
            temp = grid[i][j]
            grid[i][j] = 0
            for x, y in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                if 0<=x<m and 0<=y<n and grid[x][y]!=0:
                    backTrack(x, y, gold + grid[x][y])

            grid[i][j] = temp

        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    backTrack(i, j, grid[i][j])

        return self.ret