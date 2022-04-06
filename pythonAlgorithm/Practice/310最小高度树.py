# 最多只有两个节点作为根(反证法证明)
# 叶子节点作为根得到的高度比非叶子节点得到的要大 => 遍历叶子节点
# 从叶子节点向上到根节点，每次对其进行剪枝，最后留下的就是高度最小的根节点
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        in_degree, connect = [0] * n, defaultdict(list)
        for a, b in edges:
            in_degree[a] += 1
            in_degree[b] += 1
            connect[a].append(b)
            connect[b].append(a)
        nodes = [i for i, v in enumerate(in_degree) if v <= 1]
        while n > 2:
            n -= len(nodes)
            nxt = []
            for node in nodes:
                for other in connect[node]:
                    in_degree[other] -= 1
                    if in_degree[other] == 1:
                        nxt.append(other)
            # 剪枝
            nodes = nxt
        return nodes
