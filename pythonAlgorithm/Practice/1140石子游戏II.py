class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        for i in range(n-2, -1, -1):
            # sum(piles[i:])
            piles[i] += piles[i + 1]

        # dp[i][m] 表示从位置i开始，M=m的情况下，第一位抓的玩家能获取的最大值
        # 返回结果为dp[0][1]
        dp = [[0]*(n+1) for _ in range(n+1)]

        for i in range(n-1, -1, -1):
            for m in range(1, n+1):
                border = min(2 * m, n - i)
                # 遍历分界点
                for j in range(1, border + 1):
                    # 右半部分是bob拿的
                    dp[i][m] = max(dp[i][m], piles[i] - dp[i+j][max(j, m)])

        return dp[0][1]
    
    
# 记忆化dfs，f(i, M) === dp[i][m]
from functools import lru_cache

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        # sum(piles[i:])
        for i in range(n - 2, -1, -1):
            piles[i] += piles[i+1]
        @lru_cache(None)
        def f(i, M):
            # 全拿完，不需要给bob留了
            if n - i <= 2 * M:
                return piles[i]
            return max(piles[i] - f(i+j, max(M, j)) for j in range(1, 2*M+1))
        return f(0, 1)
