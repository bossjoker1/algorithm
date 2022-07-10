# 转换思想：堆(贪心)
# 只要是路过的加油站，之后就可以加上，但缺油的时候每次要选最多的
class Solution:
    def minRefuelStops(self, target: int, s: int, stations: List[List[int]]) -> int:
        if s >= target: return 0
        # 优先队列
        q = []
        cnt = 0
        # 加上target，方便一起处理
        stations.append([target, 0])
        for pos, oil in stations:
            if s >= target:
                return cnt
            while q and s < pos:
                temp = - heapq.heappop(q)
                s += temp
                cnt += 1
            heapq.heappush(q, -oil)

            if s < pos:
                return -1

        return cnt if s >= target else -1