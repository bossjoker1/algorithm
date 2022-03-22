# 先统计0的总数
# 遍历每个点作为分界
# 左分界为全0，有分界为全1
# 找到最少修改的分界

class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        
        m = s.count('0')
        res = m

        for x in s:
            if x == '1':
                m += 1
            else:
                m -= 1
            res = min(res, m)

        return res

class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        # dp[i]表示s[:i+1]的字符串变成单调递增所需要的最小次数
        n = len(s)
        dp, cnt = 0, 0
        for i in range(n):
            if s[i] == '1':
                cnt += 1
            else:
                # 要么把0变成1
                # 要么把前面的1都变成0
                dp = min(dp + 1, cnt)

        return dp
    