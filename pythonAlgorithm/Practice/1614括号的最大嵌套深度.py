# list 模拟栈
class Solution:
    def maxDepth(self, s: str) -> int:
        maxn = 0
        l = []
        for t in s:
            if t == '(':
                l.append(1)
                maxn = max(maxn, len(l))
            elif t == ')':
                l.pop()

        return maxn