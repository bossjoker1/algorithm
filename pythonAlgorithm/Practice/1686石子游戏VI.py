# 贪心
# 对每两组石头存在(a1, b2), (a2, b1)
# a1 - b2 - (a2 - b1) = a1 + b1 - (a2 + b2) 是否大于0
class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        n = len(aliceValues)
        sumv = [(aliceValues[i] + bobValues[i], i) for i in range(n)]
        sumv.sort(key=lambda x: x[0], reverse=True)
        val1 = val2 = 0 
        for i in range(n):
            if i % 2 == 0:
                val1 += aliceValues[sumv[i][1]]
            else:
                val2 += bobValues[sumv[i][1]]
        return 1 if val1 > val2 else (0 if val1 == val2 else -1)