# 求三个点的最小值
# 枚举两条路中间的交汇点
# 需要建立反图

class Solution:
    def minimumWeight(self, n: int, edges: List[List[int]], src1: int, src2: int, dest: int) -> int:

        def dijkstra(g:List[List[tuple]], src:int) -> List[int]:
            dis = [inf] * n
            dis[src] = 0
            # 堆优化
            q = [(0, src)]
            while q:
                d, x = heappop(q)
                if dis[x] < d:
                    continue
                for y, wt in g[x]:
                    newd = wt + dis[x]
                    if newd < dis[y]:
                        dis[y] = newd
                        heappush(q, (newd, y))

            return dis

        g = [[] for _ in range(n)]
        rg = [[] for _ in range(n)]

        for x, y, wt in edges:
            g[x].append((y, wt))
            rg[y].append((x, wt))

        d1 = dijkstra(g, src1)
        d2 = dijkstra(g, src2)
        d3 = dijkstra(rg, dest)

        
        # 将对象中对应的元素打包成一个个元组，然后返回由这些元组组成的列表
        ans = min(sum(d) for d in zip(d1, d2, d3))

        return ans if ans < inf else -1