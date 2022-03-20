import math

class Solution:
    def networkBecomesIdle(self, edges: List[List[int]], patience: List[int]) -> int:
        n = len(patience)

        def dijkstra(g:List[List[tuple]], src:int) -> List[int]:
            dis = [inf] * n
            dis[src] = 0
            # 堆优化
            q = [(0, src)]
            while q:
                d, x = heappop(q)
                if dis[x] < d:
                    continue
                for y in g[x]:
                    newd = 1 + dis[x]
                    if newd < dis[y]:
                        dis[y] = newd
                        heappush(q, (newd, y))

            return dis
        
        g = [[] for _ in range(n)]

        for x, y in edges:
            g[x].append(y)
            g[y].append(x)

        dis = dijkstra(g, 0)

        res = -1

        for i in range(1, n):
            d = patience[i]
            rtt = 2*dis[i]

            resend_times = math.ceil(rtt / d) - 1

            last_send = resend_times * d

            finish_time = last_send + rtt + 1

            res = max(res, finish_time)


        return res
    
    
# 改成bfs

def bfs(g:List[List[tuple]], src:int) -> List[int]:
    dis = [inf] * n
    dis[src] = 0
    q = deque([src])
    while q:
        cur = q.popleft()
        for x in g[cur]:
            if dis[x] != inf:
                continue
            dis[x] = dis[cur] + 1
            q.append(x)
    return dis