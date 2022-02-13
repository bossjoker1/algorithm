# 数据范围很小，肯定是暴力枚举 + 位元算
# 聊天去了，没时间做(


# 指路 1879
    
# 三进制来表示篮子的状态
class Solution:
    def maximumANDSum(self, nums: List[int], numSlots: int) -> int:
        
        @lru_cache(None)
        def dfs(cur,index):
            if index == len(nums):
                return 0
            ans = 0
            for i in range(numSlots):
                tar = cur // (3 ** i) % 3
                if tar < 2:
                    ans = max(ans,((i + 1) & nums[index]) + dfs(cur + 3 ** i,index + 1))
            return ans
        
        return dfs(0,0)


class Solution:
    def maximumANDSum(self, nums: List[int], numSlots: int) -> int:
        ans, n = 0, len(nums)
        f = [0] * (1 << (numSlots * 2))
        for i, fi in enumerate(f):
            c = i.bit_count()
            if c >= n:
                continue
            for j in range(numSlots * 2):
                if (i & (1 << j)) == 0:
                    s = i | (1 << j)
                    f[s] = max(f[s], fi + ((j // 2 + 1) & nums[c]))
                    ans = max(ans, f[s])
        return ans
    
    
    
# 最大权二分图匹配
import numpy as np
from scipy.optimize import linear_sum_assignment
class Solution:
    def maximumANDSum(self, nums: List[int], ns: int) -> int:
        nums, slots, mx = nums + [0] * (2 * ns - len(nums)), [*range(1, ns + 1)] * 2, np.zeros((ns * 2, ns * 2))
        for (i, x), (j, sn) in product(enumerate(nums), enumerate(slots)): mx[i, j] = x & sn
        return int(mx[linear_sum_assignment(-mx)].sum())
