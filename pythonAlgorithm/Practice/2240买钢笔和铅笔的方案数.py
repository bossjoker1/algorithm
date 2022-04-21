class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        res = 0
        one = total // cost1
        for i in range(one + 1):
            res += (total - cost1 * i) // cost2 + 1
        return res