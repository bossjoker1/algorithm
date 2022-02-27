class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cnt1, cnt2 = [0] * 26, [0] * 26
        n1, n2 = len(s), len(t)
        flag = True
        for i in range(n1):
            cnt1[ord(s[i]) - ord('a')] += 1
        for i in range(n2):
            cnt2[ord(t[i]) - ord('a')] += 1
        
        res = 0
        for i in range(26):
            res += abs(cnt1[i] - cnt2[i])
            
        return res
        