class Solution:
    def digitSum(self, s: str, k: int) -> str:
        n = len(s)
        while n > k:
            i = 0
            temp = ""
            while i < n:
                t = 0
                j = 0
                while j < k:
                    if i + j < n:
                        t += int(s[i+j])
                    j+=1
                i += k
                temp += str(t)
                
            s = temp
            n = len(s)
            
        return s