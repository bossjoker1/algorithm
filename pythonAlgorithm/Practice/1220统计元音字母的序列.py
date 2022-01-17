# hard

# 找递推关系，还可以用矩阵快速幂加速
# 成功ac一道hard 嘿嘿
MOD = int(1e9)+7
dp = [[0]*5 for _ in range(20005)]
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        for i in range(5):
            dp[0][i] = 1

        for i in range(1, n+1):
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]) % MOD
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % MOD
            dp[i][3] = (dp[i-1][2]) % MOD
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % MOD

        res = 0
        for i in range(5):
            res = (res + dp[n-1][i]) % MOD

        return res



# 1.暴力，题目说了数据很大需要模，递归肯定会爆
MOD = int(1e9)+7
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        self.cnt = 0
        def recursion(pre:string ,l:int):
            if(l == n):
                self.cnt += 1
                self.cnt %= MOD
                return

            if(pre == 'a'):
                recursion('e', l+1)
            elif(pre == 'e'):
                recursion('a', l+1)
                recursion('i', l+1)
            elif(pre == 'i'):
                recursion('a', l+1)
                recursion('e', l+1)
                recursion('o', l+1)
                recursion('u', l+1)
            elif(pre == 'o'):
                recursion('i', l+1)
                recursion('u', l+1)
            elif(pre == 'u'):
                recursion('a', l+1)

        recursion('a', 1)
        recursion('e', 1)
        recursion('i', 1)
        recursion('o', 1)
        recursion('u', 1)

        return self.cnt
    

