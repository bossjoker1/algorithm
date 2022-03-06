# 枚举每个字符串是不是其它字符串的子串

class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        longest_len = -1

        def is_sub(x, y):
            j = 0
            for i in range(len(y)):
                if j >= len(x):
                    break
                if x[j] == y[i]:
                    j += 1
            return j == len(x)

        for idx, s in enumerate(strs):
            if all(is_sub(s, s2) == False for idx2, s2 in enumerate(strs) if idx != idx2):
                longest_len = max(longest_len, len(s))
        return longest_len
 