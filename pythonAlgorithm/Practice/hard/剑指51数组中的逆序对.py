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
    
# 贴个树状数组类
class BIT:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 1)

    @staticmethod
    def lowbit(x):
        return x & (-x)
    
    def query(self, x):
        ret = 0
        while x > 0:
            ret += self.tree[x]
            x -= BIT.lowbit(x)
        return ret

    def update(self, x):
        while x <= self.n:
            self.tree[x] += 1
            x += BIT.lowbit(x)
