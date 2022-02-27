class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        res = 0
        for item in words:
            if len(item) < len(pref):
                continue
            
            if item[:len(pref)] == pref:
                res += 1
                
        return res