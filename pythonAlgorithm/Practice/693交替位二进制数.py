# 朴素
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        binS = bin(n)[2:]
        pre = ""
        for i in range(len(binS)):
            if binS[i] == pre:
                return False
            else:
                pre = binS[i]

        return True
