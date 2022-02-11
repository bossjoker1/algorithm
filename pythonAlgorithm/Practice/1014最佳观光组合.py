# 改了下过了。。。
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        l, r, n= [values[0], 0], [values[1],1], len(values)
        val = values[1] + values[0] - 1 
        for i in range(2, n):
            tl, tr = l, r
            if tl[0] + values[i] + tl[1] - i > val:
                r = [values[i], i]
                val = tl[0] + values[i] + tl[1] - i
            if tr[0] + values[i] + tr[1] - i > val:
                l = tr
                r = [values[i], i]
                val = tr[0] + values[i] + tr[1] - i

            if values[i] + i > l[0] + l[1]:
                l = [values[i], i]

        return val

# 再想了想发现，只需要一直维护左边那个即可，只要有比它好的立马更新
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        l, n= [values[0], 0], len(values)
        val = values[1] + values[0] - 1 
        for i in range(1, n):
            if l[0] + values[i] + l[1] - i > val:
                val = l[0] + values[i] + l[1] - i 

            if values[i] + i > l[0] + l[1]:
                l = [values[i], i]

        return val

                





