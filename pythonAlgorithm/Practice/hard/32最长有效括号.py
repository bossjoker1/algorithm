# 开个数组进行标记
# 然后求最长的连续“1”

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        res = 0
        zeros = [0] * n
        stack = []
        for i in range(n):
            if s[i] == "(":
                stack.append((s[i], i))
            else:
                if stack and stack[-1][0] == "(":
                    _, idx = stack.pop()
                    zeros[idx] = 1
                    zeros[i] = 1
        cnt = 0
        for i in range(n):
            if zeros[i] == 1:
                cnt+=1
                res = max(res, cnt)
            else:
                cnt = 0

        return res

# 动态规划

class Solution(object):
    def longestValidParentheses(self, s):
        length = len(s)
        if length == 0:
            return 0
        dp = [0] * length
        for i in range(1,length):
        		#当遇到右括号时，尝试向前匹配左括号
            if s[i] == ')':
                pre = i - dp[i-1] -1;
                #如果是左括号，则更新匹配长度
                if pre>=0 and s[pre] == '(':
                    dp[i] = dp[i-1] + 2
                    #处理独立的括号对的情形 类似()()、()(())
                    if pre>0:
                        dp[i] += dp[pre-1]
        return max(dp);