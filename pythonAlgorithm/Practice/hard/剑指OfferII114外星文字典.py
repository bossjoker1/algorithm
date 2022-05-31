# 拓扑排序
# 不合法的情况：出现环，前面的长度比后面的还长(后面的是前面的前缀)
# pairwise返回重叠对
# zip(a, b)两两组合成tuple，以短的为准
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        graph, s = defaultdict(list), set()
        for w in words:
            s = s.union(set(w))
        d = [0] * 26
        for a, b in pairwise(words):
            for ca, cb in zip(a, b):
                if ca != cb:
                    graph[ca].append(cb)
                    d[ord(cb) - ord('a')] += 1
                    break
            else: 
                if len(a) > len(b):
                    return ""
        start = [k for k in s if d[ord(k) - ord('a')] == 0]
        for ch in start:
            for nxt in graph[ch]:
                d[v := ord(nxt) - ord('a')] -= 1
                if not d[v]:
                    start.append(nxt)
        return "".join(start) if len(start) == len(s) else ""