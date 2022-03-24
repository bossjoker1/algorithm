class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        final = len(word)
        dirs = [(1, 0), (-1, 0), (0, -1), (0, 1)]
        visited = [[0] * n for _ in range(m)]
        self.res = False
        def dfs(x, y, idx):
            if board[x][y] != word[idx]:
                return
            if idx == final-1:
                self.res = True
                return
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0<=nx<m and 0<=ny<n and not visited[nx][ny]:
                    visited[nx][ny] = 1
                    dfs(nx, ny, idx+1)
                    visited[nx][ny] = 0



        for i in range(m):
            for j in range(n):
                visited[i][j] = 1
                dfs(i, j, 0)
                visited[i][j] = 0
                if self.res:
                    return True


        return False
