# 括号+通配符结合？
# 这方法完全想不到，还有三叶姐的动态规划...
class Solution:
    def checkValidString(self, s: str) -> bool:
        # 左括号的最小可能个数和最大可能个数
        l, r = 0, 0

        for item in s:
            if item == '(':
                l += 1
                r += 1
            elif item == ')':
                l -= 1
                r -= 1
            else:
                l -= 1
                r += 1

            l = max(l, 0)

            if l > r: return False

        return l == 0
