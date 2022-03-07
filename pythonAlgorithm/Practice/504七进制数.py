class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        res = []
        flag = True
        if num < 0:
            flag = False
            num = - num
        while num:
            res.append(str(num % 7))
            num //= 7

        if not flag:
            res.append("-")

        return "".join(res[::-1])
