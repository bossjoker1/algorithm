# n最多10^9，肯定不能维护整个网格的
# 对角线用截距唯一表示，即对(x, y)有对角线x+y, x-y
# 对四个方向维护一个hash表，每个灯泡照亮则计数加一，灯泡位置维护set，避免重复
class Solution:
    def gridIllumination(self, n: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        row_cnts, col_cnts, lr_cnts, rl_cnts, points = defaultdict(int), defaultdict(int), defaultdict(int), defaultdict(int), set()
        for r, c in lamps:
            if (r, c) not in points:
                points.add((r, c))
                # 用计数方便考虑不同的灯照亮同一个位置
                row_cnts[r] += 1
                col_cnts[c] += 1
                # r * (-1) + b = c
                lr_cnts[r + c] += 1
                # r + b = c
                rl_cnts[r - c] += 1
        ans = [0] * len(queries)
        for i in range(len(queries)):
            r, c = queries[i]
            # 是否照亮
            if row_cnts[r] or col_cnts[c] or lr_cnts[r + c] or rl_cnts[r - c]:
                ans[i] = 1
                for dx, dy in (0, 1), (1, 0), (0, -1), (-1, 0), (0, 0), (1, 1), (-1, 1), (1, -1), (-1, -1):
                    if ((nx := r + dx),(ny := c + dy)) in points:
                        # 移除灯泡同时照亮的各位置计数减一
                        points.remove((nx, ny))
                        row_cnts[nx] -= 1
                        col_cnts[ny] -= 1
                        lr_cnts[nx + ny] -= 1
                        rl_cnts[nx - ny] -= 1
        return ans
