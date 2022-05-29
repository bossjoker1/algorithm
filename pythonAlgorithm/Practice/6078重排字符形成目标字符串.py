from prometheus_client import Counter


class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        c1 = Counter(s)
        c2 = Counter(target)
        res = 100005
        for k, v in c2.items():
            res = min(res, c1[k]//c2[k])
            
        return res 