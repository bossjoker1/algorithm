# 递归解决
class Solution:
    @cache
    def isMatch(self, s: str, p: str) -> bool:
        if not p: return not s  # 结束条件

        first_match = (len(s) > 0) and p[0] in {s[0], '.'}
        # 先处理 `*`
        if len(p) >=2 and p[1] == '*':
            # 匹配0个 | 多个(每次匹配1个实现)
            return self.isMatch(s, p[2:]) or (first_match and self.isMatch(s[1:], p))
        
        # 处理 `.` ，匹配一个
        return first_match and self.isMatch(s[1:], p[1:])
    
# 三叶姐的递归推导，tql
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)
        f = [[False] * (m + 1) for _ in range(n + 1)]
        f[0][0] = True
        for i in range(n + 1):
            for j in range(1, m + 1):
                if j + 1 <= m and p[j] == '*': 
                    continue
                if i - 1 >= 0 and p[j - 1] != "*":
                    f[i][j] = f[i - 1][j - 1] and (s[i - 1] == p[j - 1] or p[j - 1] == ".")
                elif p[j-1] == "*":
                    f[i][j] = (j - 2 >= 0 and f[i][j - 2]) or (i - 1 >= 0 and f[i - 1][j] and (s[i - 1] == p[j - 2] or p[j - 2] == "."))
        return f[n][m]

# 调库(开玩笑
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return True if re.compile(p).fullmatch(s) else False