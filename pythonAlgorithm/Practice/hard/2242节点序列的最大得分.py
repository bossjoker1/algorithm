# 枚举边 
# nlargest product库函数
class Solution:
    def maximumScore(self, scores: List[int], edges: List[List[int]]) -> int:
        g = [[] for _ in range(len(scores))]
        for x, y in edges:
            g[x].append((scores[y], y))
            g[y].append((scores[x], x))

        for i, v in enumerate(g):
            # a-x-y-b 
            # x保存的就是与y和b不同的a
            # 因此每个点取前3个分数最大的就够了
            g[i] = nlargest(3, v)

        res = -1

        # 枚举边
        for x, y in edges:
            # product 取笛卡尔积，即取g[x]中的一个和g[y]的一个
            for (scoreA, a), (scoreB, b) in product(g[x], g[y]):
                if  y != a != b != x:
                    res = max(res, scoreA + scoreB + scores[x] + scores[y])
        return res