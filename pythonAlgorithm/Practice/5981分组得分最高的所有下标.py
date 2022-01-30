# 278周赛 2
class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pre = [0] * (n+1)
        for i in range(n):
            pre[i+1] = pre[i] + nums[i]
        maxv, res = -1, []
        for p in range(n+1):
            temp = pre[n] - pre[p]
            if p - 1 >= 0:
                temp += p - pre[p]
 
            if maxv < temp:
                maxv = temp
                res.clear()
            if maxv == temp:
                res.append(p)
                
        return res