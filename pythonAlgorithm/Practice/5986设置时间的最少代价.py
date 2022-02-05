# 唉没想到枚举，一开始想着怎么直接模拟到给定时间了
class Solution:
    def minCostSetTime(self, startAt: int, moveCost: int, pushCost: int, targetSeconds: int) -> int:
        a, res = [0] * 4, sys.maxsize
        for i in range(1, 10000):
            a[0], a[1] = i // 1000, i//100 % 10
            a[2], a[3] = i // 10 % 10, i % 10
            if a[0]*600 + a[1]*60 + a[2]*10 + a[3] != targetSeconds:
                continue
            # 忽略前导零
            j = 0
            while j < 4 and not a[j]:
                j += 1
            temp, k = 0, startAt
            while j < 4:
                if k != a[j]:
                    k = a[j]
                    temp += moveCost
                temp += pushCost
                j += 1
            res = min(res, temp)
            
        return res
