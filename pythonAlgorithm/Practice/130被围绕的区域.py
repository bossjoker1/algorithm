# 先找边界的点进行dfs，将其到的点作个标记
# 之后依然为'O'的说明被'X'围住了，修改为'X'
# 标记的点改回'O'

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        def dfs(x, y):
            if 0<=x<m and 0<=y<n and board[x][y] == 'O':
                board[x][y] = 'f'
                for dx, dy in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                    nx, ny = x + dx, y + dy
                    dfs(nx, ny)
        
        m = len(board)
        if m == 0:
            return
        n = len(board[0])

        for i in range(m):
            dfs(i, 0)
            dfs(i, n-1)
        for i in range(n):
            dfs(0, i)
            dfs(m-1, i)
            
        for i in range(m):
            for j in range(n):
                board[i][j] = 'O' if board[i][j] == 'f' else 'X'

        return board