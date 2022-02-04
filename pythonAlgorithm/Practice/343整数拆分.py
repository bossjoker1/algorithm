# 数学推导
class Solution:
    def integerBreak(self, n: int) -> int:
        if n <= 3: return n-1
        a, b = n // 3, n % 3
        if b == 0:
            return int(math.pow(3, a))
        if b == 1:
            return int(math.pow(3, a-1)*4)
        return int(math.pow(3, a)*2)
    
# 动态规划
# dp[i]表示为i的最大乘积, dp[i]可由dp[j] * (i-j) 中的最大值转移过来
# 但由于题目说必须拆分所以 还要与 j*(i-j)相比

class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0] * (n+1)
        for i in range(2, n+1):
            for j in range(i):
                dp[i] = max(dp[i], dp[j]*(i-j), j*(i-j))

        return dp[n]
    


