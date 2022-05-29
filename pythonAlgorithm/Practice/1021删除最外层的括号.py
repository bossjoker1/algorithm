# 通过指针移动模拟栈
# 加入res的时机为：右括号数量等于左括号数量
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        base = 0
        res = ""
        lcnt, rcnt = 0, 0
        for i in range(len(s)):
            if s[i] == ")":
                rcnt += 1
            else:
                lcnt += 1

            if rcnt >= lcnt:
                res += s[base+1:i]
                base = i+1
                lcnt, rcnt = 0, 0
            
        return res