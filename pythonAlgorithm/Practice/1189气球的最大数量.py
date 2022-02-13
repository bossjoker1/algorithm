# easy
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        d = defaultdict(int)
        for i in text:
            if i in ['b', 'a', 'l', 'o', 'n']:
                d[i] += 1
        maxv = 100005
        if len(d) < 5:
            return 0
        for k, v in d.items():
            if k in ['l', 'o']:
                maxv = min(maxv, v // 2)
            else:
                maxv = min(maxv, v)

        return maxv

