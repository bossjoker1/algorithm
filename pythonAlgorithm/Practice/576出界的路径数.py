MOD = int(1e9 + 7)
class Solution(object):
    def findPaths(self, m, n, N, i, j):
        dp = [{} for _ in range(N + 1)]
        dp[0][(i, j)] = 1
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        ans = 0
        for step in range(1, N + 1):
            for r, c in dp[step - 1]:
                # 前一个能抵达的状态
                count = dp[step - 1][(r, c)]
                for dr, dc in dirs:
                    nr, nc = dr + r, dc + c
                    # 出界了
                    if nr >= m or nc >= n or nr < 0 or nc < 0:
                        ans += count
                        ans %= MOD
                    # step能到达该地的其它方法
                    elif (nr, nc) in dp[step]:
                        dp[step][(nr, nc)] += count
                    # 第一次抵达
                    else:
                        dp[step][(nr, nc)] = count
        return ans % MOD