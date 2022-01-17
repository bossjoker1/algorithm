# 牛顿迭代法
# 忘光了。。
class Solution:
    def mySqrt(self, x: int) -> int:

        if x <= 1:
            return x

        r = x
        while r > x / r:
            r = (r + x/r) // 2
        return int(r)


# 大厂改编，需要精确到小数点几位

class Solution:
    def mySqrt(self, x: int) -> float:
        err = 1e-6

        x0 = 0.0
        x1 = x

        while 1:
            x0 = 0.5 * x1 + 0.5 * x / x1

            if abs(x1 - x0) < err:
                break
            x1 = x0

        return x1