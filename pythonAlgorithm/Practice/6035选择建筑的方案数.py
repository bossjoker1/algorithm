class Solution:
    def numberOfWays(self, s: str) -> int:
        n = len(s)
        pre0, pre1 = [0] * (n+1), [0]*(n+1)
        
        for i in range(1, n+1):
            pre0[i] = pre0[i-1] + (1 if s[i-1] == '0' else 0)
            pre1[i] = pre1[i-1] + (1 if s[i-1] == '1' else 0)
        res = 0 
        for i in range(n):
            if s[i] == '0':
                res += pre1[i]*(pre1[n] - pre1[i]) 
            if s[i] == '1':
                res += pre0[i]*(pre0[n] - pre0[i])
            
        return res
