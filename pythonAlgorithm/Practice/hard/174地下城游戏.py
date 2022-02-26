# dp[i][j]表示从(i, j)到终点所需的最小初始值
# dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1) 至少要为1才不会死
# 从右下到左上考虑，为什么不能反过来？需维护最大路径和，和路径中的最小值，两者重要性等价，无法进行
# 设置边界条件

class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        n, m = len(dungeon), len(dungeon[0])
        BIG = 10**9
        dp = [[BIG] * (m + 1) for _ in range(n + 1)]
        dp[n][m - 1] = dp[n - 1][m] = 1
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                minn = min(dp[i + 1][j], dp[i][j + 1])
                dp[i][j] = max(minn - dungeon[i][j], 1)

        return dp[0][0]