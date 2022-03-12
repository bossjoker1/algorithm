# 一维排序后，转换为LIS问题

class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x : (x[0], x[1]))
        n = len(pairs)
        dp = [1]*n
        for i in range(n):
            for j in range(i):
                if pairs[i][0] > pairs[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)
    
# 按第二维排序，因为第一维小于第二维，所以直接贪心即可
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x : x[1])
        n = len(pairs)
        res, temp = 1, pairs[0][1]
        for i in range(1, n):
            if pairs[i][0] > temp:
                res += 1
                temp = pairs[i][1]

        return res