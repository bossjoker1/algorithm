# 好的做法：所有与海域相连的边界点先入队，维护两个结果数组
# 并查集也可以
# 数据太水，每个点bfs能过
dir = [(0, -1), (0, 1), (1, 0), (-1, 0)]
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])
        res = []

        def bfs(x, y):
            visited = [[0]*n for _ in range(m)]
            q = deque()
            q.append((x, y))
            visited[x][y] = 1
            f1, f2 = False, False
            while q:
                cur = q.popleft()
                if cur[0] == 0 or cur[1] == 0:
                    f1 = True
                if cur[0] == m - 1 or cur[1] == n-1:
                    f2 = True
                for dx, dy in dir:
                    nx, ny = cur[0] + dx, cur[1] + dy
                    if 0<=nx<m and 0<=ny<n and not visited[nx][ny] and heights[nx][ny] <= heights[cur[0]][cur[1]]:
                        visited[nx][ny] = 1
                        q.append((nx, ny))
                         
                if f1 and f2:
                    return True

            return False


        for i in range(m):
            for j in range(n):
                if bfs(i, j):
                    res.append([i, j])

        return res