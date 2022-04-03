# 呜呜呜二分没骗成功，140/143...，会卡aaaaa...aaa类似的样例
# 扩展KMP, 这就是dl们秒解的原因？
# https://oi-wiki.org/string/z-func/

class Solution:
    def sumScores(self, s: str) -> int:
        n = len(s)
        z = [0] * n
        ans, l, r = n, 0, 0
        for i in range(1, n):
            z[i] = max(min(z[i - l], r - i + 1), 0)  # 注：不用 min max，拆开用 < > 比较会更快（仅限于 Python）
            while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                l, r = i, i + z[i]
                z[i] += 1
            ans += z[i]
        return ans