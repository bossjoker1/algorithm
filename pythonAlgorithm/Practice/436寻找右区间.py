# 二分查找
# 排序后注意维护原坐标
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        mp = defaultdict(int)
        
        for i in range(n):
            mp[(intervals[i][0], intervals[i][1])] = i

        intervals.sort(key=lambda x : (x[0], x[1]))

        res = [-1] * n


        def check(l:int, x:int) -> int:
            r = n
            while l < r:
                mid = (l + r) >> 1
                if intervals[mid][0] >= x:
                    r = mid
                else:
                    l = mid + 1

            return l

        # print(intervals)
        # print(mp)
        for i in range(n):
            idx = check(i, intervals[i][1])
            cur = mp[(intervals[i][0], intervals[i][1])]
            if idx == n:
                res[cur] = -1
            else:
                res[cur] = mp[(intervals[idx][0], intervals[idx][1])]

        return res


            
