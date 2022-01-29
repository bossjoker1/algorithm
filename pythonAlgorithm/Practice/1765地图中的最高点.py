# 多源bfs 以每个水源开始
# 指路994
class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n = len(isWater), len(isWater[0])
        dp = [[0]*n for _ in range(m)]

        dir = [(0, -1), (0, 1), (1, 0), (-1, 0)]
        q= deque()
        visit = set()
        for i in range(m):
            for j in range(n):
                if isWater[i][j]:
                    q.append((i, j))
                    visit.add((i, j))
        while q:
            x0, y0 = q.popleft()
            for dx, dy in dir:
                x, y  = x0+dx, y0+dy
                if 0<=x<m and 0<=y<n and (x, y) not in visit:
                    dp[x][y] = dp[x0][y0] + 1
                    visit.add((x, y))
                    q.append((x, y))

        return dp
    
    