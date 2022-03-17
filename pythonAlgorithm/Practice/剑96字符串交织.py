# lc97 
# 比较经典

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n1, n2, n3 = len(s1), len(s2), len(s3)
        if n3 != (n2 + n1):
            return False

        # dp[i][j]表示s1[:i]和s2[:j]交错能否拼成s3[:i+j+1]

        dp = [[False] * (n2+1) for _ in range(n1+1)]
        dp[0][0] = True
        for i in range(1, n1+1):
            dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1]
        for j in range(1, n2+1):
            dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1]

        for i in range(1, n1+1):
            for j in range(1,n2+1):
                dp[i][j] = (dp[i-1][j] and s1[i-1] == s3[i-1+j]) or (dp[i][j-1] and s3[i-1+j] == s2[j-1]) 

        return dp[n1][n2]

