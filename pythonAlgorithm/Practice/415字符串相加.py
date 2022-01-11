# 类似计组，维护一个进位就行
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        i, j = len(num1)-1, len(num2)-1
        jinwei = 0
        res = ""
        while i >= 0 or j >= 0 or jinwei != 0:
            if i >= 0:
                jinwei += ord(num1[i]) - ord('0')
                i -= 1
            if j >= 0:
                jinwei += ord(num2[j]) - ord('0')
                j -= 1

            res += str(jinwei % 10)
            jinwei //= 10
        return res[::-1]