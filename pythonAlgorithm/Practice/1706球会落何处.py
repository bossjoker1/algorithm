# dfs
class Solution:
    
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        res = [-1] * (n)
        @cache
        def DFS(x, y, border):
            # 成功退出条件
            if x >= m:
                return y
            # 失败退出条件
            if y < 0 or y >= n:
                return -1
            if grid[x][y] == 1:
                if border == 0:
                    return DFS(x, y+1, 1)
                elif border == 1:
                    return DFS(x+1, y, 0)
                else:
                    return -1

            if grid[x][y] == -1:
                if border == 0:
                    return DFS(x, y-1, -1)
                elif border == -1:
                    return DFS(x+1, y, 0)
                else:
                    return -1

        for i in range(n):
            res[i] = DFS(0, i, 0)

        return res
                    
                    
# dl写的模拟，orzzz

class Solution:
    
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        res = [0] * n

        def getVal(i):
            y, x = 0, i
            while y < m:
                dx =  x + grid[y][x]
                if dx < 0 or dx >= n:
                    return -1
                # 不同向
                if grid[y][dx] != grid[y][x]:
                    return -1
                y += 1
                x = dx

            return x

        for i in range(n):
            res[i] = getVal(i)

        return res
                        


