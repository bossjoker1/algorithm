class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        dp = [[0]*2 for _ in range(20000)]
        for s in words:
            temp = ord(s[0])*100 + ord(s[1])
            temp2 = ord(s[1])*100 + ord(s[0])
            if s[0] == s[1]:
                dp[temp][0] += 1
                dp[temp][1] = 2
            else:
                    dp[temp][0] += 1
                    dp[temp][1] = temp2
        cnt = 0
        flag = True
        for i in range(20000):
            if dp[i][1] == 2:
                if dp[i][0] % 2 == 0:
                    cnt += dp[i][0] * 2
                elif flag:
                    cnt += dp[i][0]  * 2
                    flag = False
                else:
                    cnt += (dp[i][0] - 1) * 2
            elif dp[i][1] != 0:
                cnt += min(dp[i][0], dp[dp[i][1]][0])*4
                dp[dp[i][1]][1] = 0
        
        return cnt