# 贪心
# 回答数相同的分为一组，多的需要额外补齐
# 向上取整的写法=>可以不借助函数

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        c = Counter(answers)
        res = sum((x+y) // (y+1) * (y+1)  for y, x in c.items())
        return res