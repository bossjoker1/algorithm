# 过年，就搞个简单题算了哈哈
class Solution:
    def numberOfSteps(self, num: int) -> int:
        res = 0
        while num != 0:
            num = num - 1 if num & 1 else num >> 1
            res += 1

        return res