# 双周赛
class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        
        ts = sorted(cost, key=lambda x : -x)
        
        res, i = 0, 0
        n = len(cost)
        cnt = 0
        while i < n:
            if cnt != 2:
                res += ts[i]
                i += 1
                cnt += 1
            else:
                i += 1
                cnt = 0
        return res