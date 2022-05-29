class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dir = [(0, -1), (0, 1), (-1, 0), (1, 0)]

        def dijkstra() -> List[int]:
            dis = [inf] * (m*n)
            dis[0] = (0 if grid[0][0] == 0 else 1)
            # 堆优化
            q = [(dis[0], 0)]
            while q:
                d, x = heappop(q)
                if dis[x] < d:
                    continue
                for dx, dy in dir:
                    nx, ny = x // n + dx, x % n + dy
                    y = nx * n + ny
                    if 0<=nx<m and 0<=ny<n:
                        newd = (0 if grid[nx][ny] == 0 else 1)  + dis[x]
                        if newd < dis[y]:
                            dis[y] = newd
                            heappush(q, (newd, y))

            return dis
        
        dis = dijkstra()
        
        return dis[m*n-1]   