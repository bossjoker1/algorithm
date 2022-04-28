# 水题 easy
class Solution:
    def checkRecord(self, s: str) -> bool:
        A, L = 0, 0

        for i in range(len(s)):
            if s[i] == 'L':
                L += 1
                if L >= 3:
                    return False
            else:
                L = 0
                if s[i] == 'A':
                    A +=1
                    if A >= 2:
                        return False

        return True