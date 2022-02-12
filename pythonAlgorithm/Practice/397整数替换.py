# python 记忆化直接加 @cache ?
class Solution:
    @cache
    def integerReplacement(self, n: int) -> int:
        if n == 1:
            return 0
        if n % 2 == 0:
            return 1 + self.integerReplacement(n // 2)
        return 2 + min(self.integerReplacement(n // 2), self.integerReplacement(n // 2 + 1))


# 位运算 => 贪心
# n+1 , n-1 哪一步何时受益更大
class Solution:
    def integerReplacement(self, n: int) -> int:
        ans = 0
        while n != 1:
            if n % 2 == 0:
                n >>= 1
            else:
                if n != 3 and (n >> 1) & 1 :
                    n = n + 1
                else:
                    n = n - 1
            ans += 1
        return ans