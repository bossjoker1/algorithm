'''BIT：Binary Indexed Tree 树状数组'''
class NumArray:
    
    '''自定义lowbit函数'''
    def lowbit(self, x: int) -> int:
        return x&(-x)

    def __init__(self, nums: List[int]):
        self.tree = [0] + nums              # 构造出的BIT空间比原nums多一，第1个下标0不用
        for i in range(1, len(self.tree)):  # 这种方式构造的BIT时间复杂度为O(n)
            j = i + self.lowbit(i)          # 构造BIT的巧妙方式
            if j < len(self.tree):
                self.tree[j] += self.tree[i]

    def update(self, index: int, val: int) -> None:
        pre_val = self.sumRange(index, index)   # index：在原nums中的位置
        delta = val - pre_val           # 变更值
        i = index + 1                   # i: 对应数值在BIT中的位置（index+1）
        while i < len(self.tree):
            self.tree[i] += delta
            i += self.lowbit(i)

    '''自定义前缀和preSum函数'''
    def preSum(self, index: int) -> int:    # index：在原nums中的位置
        i = index + 1                       # i: 对应数值在BIT中的位置（index+1）
        summ = 0
        while i:
            summ += self.tree[i]
            i -= self.lowbit(i)
            # i &= i-1        # 跟上一行等价
        return summ
    
    def sumRange(self, left: int, right: int) -> int:
        return self.preSum(right) - self.preSum(left-1)   # right对应的前缀和



# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)

# 线段树
class NumArray:

    def __init__(self, nums: List[int]):
        n = len(nums)
        self.tr = [None] * (4 * n)
        self.nums = nums
        self.build(1, 1, n)
        for i, num in enumerate(nums):
            self.update_tree(1, i + 1, nums[i])

    def update(self, index: int, val: int) -> None:
        self.update_tree(1, index + 1, val - self.nums[index])
        self.nums[index] = val

    def sumRange(self, left: int, right: int) -> int:
        return self.query(1, left + 1, right + 1)

    def build(self, u, l, r):
        self.tr[u] = Node(l, r)
        if l < r:
            mid = (l + r) >> 1
            self.build(u << 1, l, mid)
            self.build(u << 1 | 1, mid + 1, r)
    
    def update_tree(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v += v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.update_tree(u << 1, x, v)
        else:
            self.update_tree(u << 1 | 1, x, v)
        self.pushup(u)
    
    def query(self, u, l , r):
        if l <= self.tr[u].l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        ans = 0
        if l <= mid:
            ans += self.query(u << 1, l, r)
        if r > mid:
            ans += self.query(u << 1 | 1, l, r)
        return ans
    
    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v

class Node:
    def __init__(self, l, r):
        self.l, self.r = l, r
        self.v = 0
