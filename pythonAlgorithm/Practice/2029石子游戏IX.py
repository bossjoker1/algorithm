# 找到分类讨论的关键
# 此题首先就是按照取模3为0，1，2分类
# 0具有特殊性，可以作为分类的大前提

class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        s = [0, 0, 0]
        for i in stones:
            s[i%3] += 1
        
        if s[0] % 2 == 0:
            return s[1] > 0 and s[2] > 0
        else:
            return abs(s[1] - s[2]) > 2