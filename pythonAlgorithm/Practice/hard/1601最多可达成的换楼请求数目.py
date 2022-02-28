# 数据量小，直接状态压缩
class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        num = len(requests)
        snum = 1 << num
        res = 0
        for mask in range(snum):
            dp, cnt = [0] * n, 0
            for i in range(num):
                if (mask >> i) & 1:
                    cnt += 1
                    dp[requests[i][0]] -= 1
                    dp[requests[i][1]] += 1
            flag = True
            for i in range(n):
                if dp[i] != 0:
                    flag = False
            if flag:
                res = max(res, cnt)

        return res