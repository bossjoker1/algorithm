# 先按照start排序
# 然后再比较end，需要注意end的不同情况

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        # start按升序排列
        temp = sorted(intervals)
        ts, te = temp[0][0], temp[0][1]
        for i, v in enumerate(temp):
            if v[0] <= te:
                te = max(te, v[1])
            else:
                # 上一个合并区间
                res.append([ts, te])
                ts = v[0]
                te = v[1]
            if i == len(temp)-1:
                # 当前区间加入
                res.append([ts, te])
        return res

