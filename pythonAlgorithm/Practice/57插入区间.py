class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        if n == 0:
            return [newInterval]
        nl, nr = newInterval
        res = []
        temp = []

        if nl <= intervals[0][0]:
            temp.append(newInterval)
            temp.extend(intervals)
        elif nl >= intervals[n-1][0]:
            temp = intervals.copy()
            temp.append(newInterval)

        else:
            for i in range(n):
                if  nl <= intervals[i][0]:
                    temp.append(newInterval)
                temp.append(intervals[i]) 
            
        print(temp)   
        ts, te = temp[0][0], temp[0][1]
        for i, v in enumerate(temp):
            if v[0] <= te:
                te = max(te, v[1])
            else:
                res.append([ts, te])
                ts = v[0]
                te = v[1]
            if i == len(temp)-1:
                res.append([ts, te])
        return res
