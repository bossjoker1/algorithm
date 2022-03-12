class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[False] * (n+1) for i in range(m+1)]
        dp[0][0] = True
        
        for j in range(1, n+1):
            if p[j-1] == "*":
                dp[0][j] = dp[0][j-1]

        for i in range(1, m+1):
            for j in range(1, n+1):
                if s[i-1] == p[j-1] or p[j-1] == '?':
                    dp[i][j] = dp[i-1][j-1]
                elif p[j-1] == '*':
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]

        return dp[-1][-1]

# 参考正则表达式的dfs解法
class Solution:
    @cache
    def isMatch(self, s: str, p: str) -> bool:
        if not p:
            return not s

        if not s:
            # 需要特别注意
            return not p or set(p) == {"*"}

        first_match = (len(s) > 0) and p[0] in {s[0], '?'}
        if p[0] == '*':
            return self.isMatch(s, p[1:]) or self.isMatch(s[1:], p)

        return first_match and self.isMatch(s[1:], p[1:])
        