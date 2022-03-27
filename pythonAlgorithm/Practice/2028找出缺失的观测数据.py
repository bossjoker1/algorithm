# 模拟
class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        s = mean * (m + n)
        nsum = s - sum(rolls)
        if nsum / n > 6.0 or nsum / n < 1.0:
            return []

        res = [(nsum// n)] * n

        plus = nsum % n

        for i in range(n):
            if plus > 0:
                while res[i] < 6 and plus > 0:
                    res[i] += 1
                    plus -= 1
            else:
                break

        return res
    
# 直接构造，余数均摊
class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        s = mean * (m + n)
        nsum = s - sum(rolls)
        if nsum / n > 6.0 or nsum / n < 1.0:
            return []

        r = nsum % n

        return [nsum // n] * (n-r) + [nsum//n + 1] * r