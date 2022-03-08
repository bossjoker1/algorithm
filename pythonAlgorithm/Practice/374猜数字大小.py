# 二分 而且check函数给你写好了
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        l, r = 1, n
        while l <= r:
            mid = (l + r) >> 1
            f = guess(mid)
            if f == 0:
                return mid
            elif f == -1:
                r = mid
            else:
                l = mid + 1
        return 0