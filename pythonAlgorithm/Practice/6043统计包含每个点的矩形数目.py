# 一开始想的是差分 + 离散化
# 看提示发现，高度数据量很小，可以直接枚举
# 然后对宽度二分查找，bisect_left还是比手写的好用嘿嘿
class Solution:
    def countRectangles(self, rectangles: List[List[int]], points: List[List[int]]) -> List[int]:
        n, m = len(rectangles), len(points)
        res = []
        heights = [[] for _ in range(101)]

        for x, y in rectangles:
            heights[y].append(x)

        for i in range(1, 101):
            heights[i].sort()

        for px, py in points:
            cnt = 0
            for i in range(py, 101):
                l = len(heights[i])
                if len(heights[i]) == 0:
                    continue
                cnt += l-bisect_left(heights[i], px)
            res.append(cnt)

        return res