# 一开始 topo + 排序，属于是惯性思维了，能做
# 实际上 bfs 从0开始，记录它的子节点包括孙子节点
# 需要每次维护set去重，这样依次从数小的节点给其所有的子节点加上祖先节点
# 最终实现的就是有序的

class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
        
        ans = [[] for _ in range(n)]
        for i in range(n):
            q = deque(g[i])
            seen = set(g[i])
            while q:
                u = q.popleft()  # 子节点
                ans[u].append(i) # 子节点记录祖先节点
                for v in g[u]:
                    if v not in seen:
                        seen.add(v)
                        q.append(v)
        return ans