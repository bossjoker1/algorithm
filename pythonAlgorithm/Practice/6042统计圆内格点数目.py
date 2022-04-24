# 数据量小，直接暴力枚举正方形中的点
# 注意 "**" 很耗时，所以平方就用乘法
class Solution:
    def countLatticePoints(self, circles: List[List[int]]) -> int:
        n = len(circles)

        s = set()

        for x, y, r in circles:
            for dx in range(x-r, x+r+1):
                for dy in range(y-r, y+r+1):
                    if (dx-x)*(dx-x) + (dy-y)*(dy-y) <= r*r:
                        s.add((dx, dy))

        return len(s)