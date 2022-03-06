class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        m, n = len(a), len(b)
        return -1 if a == b else max(m, n) 