# 数学题，判断包含2, 5的个数就行，复杂度大概在O(nlogn)
class Solution:
    def trailingZeroes(self, n: int) -> int:
        res = 0
        cnt5 = 0
        for i in range(n+1):
            temp = i
            while temp != 0 and temp % 5 == 0:
                cnt5 += 1
                temp //= 5

        return cnt5

# 公式：直接求n!中的质因数为5的个数
# O(logn)
class Solution:
    def trailingZeroes(self, n: int) -> int:
        return n // 5 + self.trailingZeroes(n//5) if n  else 0