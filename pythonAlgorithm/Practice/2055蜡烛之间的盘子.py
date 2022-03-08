# 前缀和 + 维护最左最优边界
# 三次遍历做准备工作

class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        preSum = [0] * (n+1)
        for i in range(1, n+1):
            preSum[i] = preSum[i-1] + (1 if s[i-1] == '*' else 0)

        left, right = [0] * n, [0] * n
        r, l = -1, -1
        for i in range(n-1, -1, -1):
            if s[i] == '|':
                r = i
            left[i] = r
        for i in range(n):
            if s[i] == '|':
                l = i
            right[i] = l
        res = []
        for l, r in queries:
            i1, i2 = left[l], right[r]
            if (i1 == -1 or i1 >= r) or (i2 == -1 or i2 <= l):
                res.append(0)
                continue
            res.append(preSum[i2] - preSum[i1])

        return res  
