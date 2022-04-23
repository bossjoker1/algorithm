# 对每一个点都用dijkstra
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        g = [[] for _ in range(n)]
        for x, y, w in edges:
            g[x].append((y, w))
            g[y].append((x, w))

        res, minn = -1, 105

        def dijkstra(g:List[List[tuple]], src:int) -> List[int]:
            dis = [inf] * n
            dis[src] = 0
            # 堆优化
            q = [(0, src)]
            while q:
                d, x = heappop(q)
                if dis[x] < d:
                    continue
                for y, w in g[x]:
                    newd = w + dis[x]
                    if newd < dis[y]:
                        dis[y] = newd
                        heappush(q, (newd, y))

            return dis

        for i in range(n):
            dis = dijkstra(g, i)
            cnt = 0
            for j in range(n):
                if j == i:
                    continue
                if dis[j] <= distanceThreshold:
                    cnt += 1
            if cnt <= minn:
                minn = cnt
                res = i

        return res
