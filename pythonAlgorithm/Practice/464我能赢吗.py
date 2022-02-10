class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if maxChoosableInteger >= desiredTotal: return True
        if (1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal: return False

        def dfs(state, desiredTotal, dp):
            if dp[state] != None:
                return dp[state]
            for i in range(1, maxChoosableInteger + 1):
                cur = 1 << (i - 1)
                if cur & state != 0:
                    continue
                
                if i >= desiredTotal or not dfs(cur | state, desiredTotal - i, dp):
                    dp[state] = True
                    return True
            dp[state] = False
            return False
        
        return dfs(0, desiredTotal, [None] * (1 << maxChoosableInteger))
