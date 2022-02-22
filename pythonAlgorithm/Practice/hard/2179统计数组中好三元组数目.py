class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        # 设在nums1中有下标 i < j < k 的 x,y,z 值
        # f[i] = pos2[nums[i]]
        # 则好三元组满足f[i] < f[j] < f[k]
        # 设left[j]为在j左侧的元素且满足f[i] < f[j]的个数
        # right[j]同理

        n = len(nums1)

        pos2 = dict( (nums2[i], i) for i in range(n))

        f = [pos2[nums1[i]] for i in range(n)]

        # bit板子
        # 计数加一
        def add(x):
            while x <= n:
                t[x] += 1
                x += (x & (-x))
        
        # 区间和
        def query(x):
            res = 0
            while x:
                res += t[x]
                x -= (x & (-x))
            return res

        left, right = [0] * n, [0] * n

        t = [0] * (n+1)
        for i in range(n):
            left[i] = query(f[i])
            add(f[i]+1)
        t = [0] * (n+1)
        for i in range(n-1, -1, -1):
            right[i] = n - i - 1 - query(f[i]+1)
            add(f[i]+1)

        res = 0
        for i in range(n):
            res += left[i] * right[i]

        return res

