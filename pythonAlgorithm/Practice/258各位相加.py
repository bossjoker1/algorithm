class Solution:
    def addDigits(self, num: int) -> int:
        while True:
            ans = 0
            while num:
                ans += num % 10
                num //= 10
            if ans < 10:
                return ans
            else:
                num = ans 

# 进阶 O(1)的时间复杂度？
# 差值为9的倍数，%9可得各位和

class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0: return 0
        return (num - 1) % 9 + 1 