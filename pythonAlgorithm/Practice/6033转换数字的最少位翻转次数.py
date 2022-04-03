class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        res = 0
        for i in range(31):
            if (goal >> i) & 1 != (start >> i) & 1:
                res += 1
                
        return res
            