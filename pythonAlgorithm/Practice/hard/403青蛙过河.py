# 挑战hard

class Solution:
    def canCross(self, stones: List[int]) -> bool:
        if stones[1] != 1:
            return False
        n = len(stones)
        dp = [[False] * (n+1) for _ in range(n)]
        dp[0][0] = True
        for i in range(1, n):
            for j in range(i-1,-1,-1):
                k = stones[i] - stones[j]
                if k > j + 1:break
                dp[i][k] = dp[j][k-1] or dp[j][k] or dp[j][k+1]
                if dp[n-1][k]:
                    return True

        return False
        