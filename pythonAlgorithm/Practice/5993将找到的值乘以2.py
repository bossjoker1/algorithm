# 278周赛 1
class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        res = []
        for item in nums:
            if item != 0 and item % original == 0:
                res.append(item // original)
                
        res.sort()
        temp = original
        for i in res:
            if temp * i == original:
                original *= 2
                
        return original