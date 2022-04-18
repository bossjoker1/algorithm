# 好家伙，提示说堆，我就直接陷进去了，但是不光需要维护当前最近可以开始的任务，还需要先把多的做完
# 否则后面会增加多个缓冲的时间
# 思路是找到最多的那个任务A，将它作为大任务，每次大任务就是A _ _ (n=2) 共 (n+1)个长度
# 如果有多个大任务，则执行最后，出现 A B C D ... 等等 即需要加上大任务的数量
# 任务长度和算出的时间取最大值

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = collections.Counter(tasks)

        # 最多的执行次数
        maxExec = max(freq.values())
        # 具有最多执行次数的任务数量
        maxCount = sum(1 for v in freq.values() if v == maxExec)

        return max((maxExec - 1) * (n + 1) + maxCount, len(tasks))

## 我写的只考虑了最近时间的代码...
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cntMap = Counter(tasks)
        res = 0
        pile = []

        for k, v in cntMap.items():
            pile.append((0, k))

        while pile:
            print(pile)
            cur = heappop(pile)
            res = max(res, cur[0]) + 1
            print(res, cur)
            cntMap[cur[1]] -= 1
            if cntMap[cur[1]] > 0:
                heappush(pile, (res + n, cur[1]))

        return res