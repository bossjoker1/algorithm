# 动态规划 f[p][x][y] 为从(x, y)出发，步数不超过p仍在棋盘中的概率

class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        # 三维数组的写法，多维以此类推
        dp = [[[0] * n for _ in range(n)] for _ in range(k + 1)]
        for step in range(k + 1):
            for i in range(n):
                for j in range(n):
                    if step == 0:
                        dp[step][i][j] = 1
                    else:
                        for di, dj in ((-2, -1), (-2, 1), (2, -1), (2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2)):
                            ni, nj = i + di, j + dj
                            if 0 <= ni < n and 0 <= nj < n:
                                dp[step][i][j] += dp[step - 1][ni][nj] / 8
        return dp[k][row][column]

# 记忆化递归
class Solution:
    def knightProbability(self, N, K, r, c):
        """
        :type N: int
        :type K: int
        :type r: int
        :type c: int
        :rtype: float
        """
        memo = {}
        moves = ((-1, -2), (-2, -1),(-2, 1), (-1, 2),(1, -2), (2, -1),(2, 1), (1, 2))
        def dfs(K, r, c):
            if r < 0 or c < 0 or r >= N or c >= N:
                return 0
            if K == 0:
                return 1
            if (K, r, c) in memo:
                return memo[(K, r, c)]
            p = 0
            for move in moves:
                p += dfs(K-1, r+move[0], c+move[1])
            p /= 8.0
            memo[(K, r, c)] = p
            return p
        return dfs(K, r, c)

