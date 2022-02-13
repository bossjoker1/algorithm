# 这个稍微简单点，直接状压dp即可
# 题解有 "模拟退火" ，惊艳到了

class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        f = [float("inf")] * (1 << n)
        f[0] = 0

        for mask in range(1, 1 << n):
            c = bin(mask).count("1")
            for i in range(n):
                if mask & (1 << i):
                    # 可以于nums2[i]位匹配
                    f[mask] = min(f[mask], f[mask ^ (1 << i)] + (nums1[c - 1] ^ nums2[i]))
        
        return f[(1 << n) - 1]