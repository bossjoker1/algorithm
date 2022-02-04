# 没什么技术含量

class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        maxv, cnt = -1, 0
        for l, v in rectangles:
            minv = min(l, v)
            if minv > maxv:
                cnt = 1
                maxv = minv
                continue
            if minv == maxv:
                cnt += 1

        return cnt