# lc崩了一会
# 水题
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i, n = 0, len(bits)
        while i < n:
            if bits[i] == 1:
                i += 2
            else:
                if i == n - 1:
                    return True
                i += 1
        return False