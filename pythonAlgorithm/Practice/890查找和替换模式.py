# hash表模拟

class Solution:

    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:

        def check(s, p):
            if len(s) != len(p):
                return False
            return len(set(s)) == len(set(p)) == len(set(zip(s, p)))

        return [w for w in words if check(w, pattern)]