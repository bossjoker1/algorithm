# 模拟 + 找规律
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        n = len(s)
        if n == 1 or numRows == 1:
            return s
        res = ""
        for i in range(numRows):
            for j in range(i, n, 2*numRows - 2):
                res += s[j]
                if 0 < i < numRows - 1 and j + 2*numRows - 2 - 2 * i < n: 
                    res += s[j + 2*numRows - 2 - 2*i]
        return res