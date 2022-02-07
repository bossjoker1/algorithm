# 排列组合
# 没什么意思
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0: return 1
        if n==1: return 10
        res = 10
        a = 9
        for i in range(2, n+1):
            a *= 9-i+2
            res += a
        return res 
            
