# 趁热打铁

class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def add(x, n):
            while x <= n:
                t[x] += 1
                x += (x & (-x))

        def query(x):
            res = 0
            while x:
                res += t[x]
                x -= (x & (-x))
            return res

        n = len(nums)
        temp = sorted(nums)
        # 离散化
        for i in range(n):
            nums[i] = bisect.bisect_left(temp, nums[i]) + 1

        t = [0] * (n+1)
        res = 0
        for i in range(n-1, -1, -1):
            res += query(nums[i]-1)
            add(nums[i], n)
        return res