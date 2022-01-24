# hard
# bfs 维护最短路径和次短路径两个dist数组
# 根据题意简化为无向无权图
# 考虑红灯如何影响总时间，动态边权？=> 在实际走时无序考虑，根据step数可直接确定

class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        graph = [[] for _ in range(n+1)]
        # 建立无向图
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])

        # dist2存次短路径长度
        dist, dist2 = [float('inf')]* (n+1), [float('inf')]* (n+1)
        dist[0] = 0
        q = deque([(1, 0)])
        while dist2[n] == float('inf'):
            p = q.popleft()
            for y in graph[p[0]]:
                # 视为无权图，记录step即可
                d = p[1] + 1 
                if d < dist[y]:
                    dist[y] = d
                    q.append((y, d))
                elif dist[y] < d <dist2[y]:
                    # 满足此段路经，也加入到队列
                    dist2[y] = d
                    q.append((y, d))

        ans = 0
        for _ in range(dist2[n]):
            if ans %(2*change) >= change:
                # 需等红灯变绿灯
                ans += change*2 - ans %(change*2)
            ans += time

        return ans

