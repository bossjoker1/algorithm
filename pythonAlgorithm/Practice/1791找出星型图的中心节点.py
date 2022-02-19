# 水题
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        memo = set()
        for x, y in edges:
            if x not in memo:
                memo.add(x)
            else:
                return x
            if  y not in memo:
                memo.add(y)
            else:
                return y
        return 0
    
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        x, y = edges[0]
        tx, ty = edges[1]
        if x == tx or x == ty:
            return x
        else:
            return y