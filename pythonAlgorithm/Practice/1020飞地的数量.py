# 从可以到达边缘的点开始dfs
# 可以用并查集，但也没多大必要

direc = [[-1,0], [1,0], [0,-1], [0, 1]]
class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        q = deque()

        for i in range(m):
            for j in range(n):
                if i == 0 or i == m-1 or j == 0 or j == n-1:
                    if grid[i][j]:
                        q.append((i, j))
                        grid[i][j] = 0

                        while q:
                            tx, ty = q.popleft()
                            for dx, dy in direc:
                                x, y = tx + dx, ty + dy

                                if 0 <= x < m  and 0 <= y < n and grid[x][y]:
                                        q.append((x, y))
                                        grid[x][y] = 0

        return sum([sum(row) for row in grid])
                                


