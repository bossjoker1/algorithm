class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        n = len(costs)
        a, b, c = costs[0][0], costs[0][1], costs[0][2]
        for i in range(1, n):
            d = min(b, c) + costs[i][0]
            e = min(a, c) + costs[i][1]
            f = min(a, b) + costs[i][2]
            a, b, c = d, e, f

        return min(a, b, c)