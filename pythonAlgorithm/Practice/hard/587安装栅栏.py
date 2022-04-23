# Andrew算法，学到了但没完全学到，太🐂了
# 凸包定理 O(logn)
class Solution:
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        # 判断是否逆时针左拐
        def cross(p: List[int], q: List[int], r: List[int]) -> int:
            return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0])

        n = len(trees)
        if n < 4:
            return trees

        # 按照 x 从小到大排序，如果 x 相同，则按照 y 从小到大排序
        trees.sort()

        hull = [0]  # hull[0] 需要入栈两次，不标记
        used = [False] * n
        # 求凸包的下半部分
        for i in range(1, n):
            while len(hull) > 1 and cross(trees[hull[-2]], trees[hull[-1]], trees[i]) < 0:
                used[hull.pop()] = False
            used[i] = True
            hull.append(i)
        # 求凸包的上半部分
        m = len(hull)
        for i in range(n - 2, -1, -1):
            if not used[i]:
                while len(hull) > m and cross(trees[hull[-2]], trees[hull[-1]], trees[i]) < 0:
                    used[hull.pop()] = False
                used[i] = True
                hull.append(i)
        # hull[0] 同时参与凸包的上半部分检测，因此需去掉重复的 hull[0]
        hull.pop()

        return [trees[i] for i in hull]

