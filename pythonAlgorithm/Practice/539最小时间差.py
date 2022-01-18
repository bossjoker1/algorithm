# 没什么意思
# 转换为分钟
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        # 优化
        if len(timePoints) > 1440:
            return 0
        # 学了点骚操作
        time = [int(_[:2])*60 + int(_[-2:]) for _ in timePoints]
        time.sort()
        res = 1440 + time[0] - time[-1]
        for i, j in zip(time[0:], time[1:]):
            res  = min(res, j-i)
        return res