# 多源dfs 指路1765

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        # dp = [[0]*n for _ in range(m)]
        dir = [(0, -1), (0, 1), (1, 0), (-1, 0)]
        q= []
        visit = set()
        t = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    visit.add((i, j))
                elif grid[i][j] == 2:
                    q.append((i, j))
        while visit:
            nxt = []
            while q:
                x0, y0 = q.pop()
                for dx, dy in dir:
                    x, y  = x0+dx, y0+dy
                    if 0<=x<m and 0<=y<n and (x, y) in visit:
                        visit.remove((x, y))
                        nxt.append((x, y))
            # 永远走不到的
            if not nxt and visit:
                return -1
            q = nxt
            t += 1

        return t
