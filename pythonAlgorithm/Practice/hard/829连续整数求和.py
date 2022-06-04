class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        res = 0
        i = 1
        while N > 0:
            res += 1 if (N % i == 0) else 0
            N -= i
            i += 1

        return res