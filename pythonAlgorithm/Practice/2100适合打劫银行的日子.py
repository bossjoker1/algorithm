# 前缀 后缀 dp
class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        if n == 0 or n < 2 * time + 1:
            return []
        if time == 0:
            return [i for i in range(n)]
        
        pre, post = [0] * n, [0] * n
        for i in range(1, n):
            pre[i] = 1 + pre[i-1] if security[i] <= security[i-1] else 0
            post[n-i-1] = 1 + post[n-i] if security[n-i-1] <= security[n-i] else 0
        res = []
        for i in range(time, n-time):
            if pre[i] >= time and post[i] >= time:
              res.append(i)

        return res
