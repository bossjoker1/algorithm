# 周赛hard，跨不过去呜呜呜
# 想不出来啊

class Solution:
    def minimumFinishTime(self, tires: List[List[int]], changeTime: int, numLaps: int) -> int:
        # 限制上界，指数增加，一定程度后比换轮胎花费的时间更长
        INF = 2 * 10 ** 8
        min_sec = [INF] * 18
        sum_sec = [0] * len(tires)

        # 一个轮胎跑i圈需要的最少时间，通过遍历求得
        for x in range(1, 18):
            for i, (f, r) in enumerate(tires):
                sum_sec[i] = min(sum_sec[i] + f, INF)  # 累加该轮胎连续使用所消耗的时间
                min_sec[x] = min(min_sec[x], sum_sec[i])
                # 耗时递增
                tires[i][0] = min(f * r, INF)

        # f[i]定义为跑i圈所需的最短时间
        # 枚举跑j圈所需的最短时间
        f = [0] * (numLaps + 1)
        for i in range(1, numLaps + 1):
            f[i] = changeTime + min(f[i - j] + min_sec[j] for j in range(1, min(18, i + 1)))
        
        # 第一次也默认换了轮胎
        # 结果要减去
        return f[numLaps] - changeTime