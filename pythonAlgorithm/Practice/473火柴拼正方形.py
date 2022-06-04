# 状态压缩: dp或者记忆化搜素
# 借助python的cache

class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        total = sum(matchsticks)
        if total % 4 != 0:
            return False
        line = total // 4
        if any(num > line for num in matchsticks):
            return False
        n = len(matchsticks)
        final = (1 << n) - 1
        
        @lru_cache(None)
        def dfs(state, cur):
            if cur == line:
                cur = 0
                # 需要每条边都选了
                if state == final:
                    return True
            for i in range(n):
                # 没有选i，且选了之后的和≤line
                # 则尝试选它
                if not 1 << i & state and cur + matchsticks[i] <= line:
                    if dfs(1 << i | state, cur + matchsticks[i]):
                        return True
            return False
        
        return dfs(0, 0)
