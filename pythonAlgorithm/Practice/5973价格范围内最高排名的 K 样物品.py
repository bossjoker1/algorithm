# 双周赛
# 居然没做出来，明明想的都差不多了

dirs = ((-1, 0), (1, 0), (0, -1), (0, 1))

class Solution:
    def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
        ans = []
        m, n = len(grid), len(grid[0])
        low, high = pricing
        sx, sy = start
        # 标记是否访问
        vis = {(sx, sy)}
        q = [(sx, sy)]
        while q:  # 分层 BFS
            # 此时 q 内所有元素到起点的距离均相同，因此按照题目中的第 2~4 关键字排序后，就可以将价格在 [low, high] 内的位置加入答案
            # 学到了呜呜呜
            q.sort(key=lambda p: (grid[p[0]][p[1]], p))
            ans.extend(p for p in q if low <= grid[p[0]][p[1]] <= high)
            if len(ans) >= k:
                return ans[:k]
            tmp = q
            q = []
            for p in tmp:
                for d in dirs:
                    x, y = p[0] + d[0], p[1] + d[1]
                    if 0 <= x < m and 0 <= y < n and grid[x][y] and (x, y) not in vis:
                        vis.add((x, y))
                        q.append((x, y))
        return ans

