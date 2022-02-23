# 逆序对问题
# 数据范围更大，则可能需要离散化

N = 20005
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        
        def add(x):
            while x <= N:
                t[x] += 1
                x += (x & (-x))

        def query(x):
            res = 0
            while x:
                res += t[x]
                x -= (x & (-x))
            return res

        maxn, n = max(nums), len(nums)

        t = [0] * N
        res = []
        for i in range(n-1, -1, -1):
            res.append(query(nums[i] - 1 + 10001))
            add(nums[i] + 10001)
        
        res.reverse()
        return res

# python内置二分查找实现离散化

# 逆序对问题
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        
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
        res = []
        for i in range(n-1, -1, -1):
            res.append(query(nums[i]-1))
            add(nums[i], n)
        res.reverse()
        return res

