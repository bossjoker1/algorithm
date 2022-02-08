class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        if not nums: return nums
        if len(nums) == 1: return nums
        l = len(nums)
        nums.sort()

        dp = [[i] for i in nums]
        
        for i in range(1, l):
            for j in range(i-1, -1, -1):
                if nums[i]%nums[j] == 0:
                    dp[i] = max(dp[j] + [nums[i]], dp[i],key=len)

        return max(dp,key=len)
    
# 上面这个方法对每个位置都需要维护一个结果数组，空间耗费大，因为实际只需要最长的那个
# 可以考虑用一个数组来维护坐标，进行回溯

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        f, g = [0] * n, [0] * n
        for i in range(n):
            # 至少包含自身一个数，因此起始长度为 1，由自身转移而来
            length, prev = 1, i
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    # 如果能接在更长的序列后面，则更新「最大长度」&「从何转移而来」
                    if f[j] + 1 > length:
                        length = f[j] + 1
                        prev = j
            # 记录「最终长度」&「从何转移而来」
            f[i] = length
            g[i] = prev

        # 遍历所有的 f[i]，取得「最大长度」和「对应下标」
        max_len = idx = -1
        for i in range(n):
            if f[i] > max_len:
                idx = i
                max_len = f[i]
        
        # 使用 g[] 数组回溯出具体方案
        ans = []
        while len(ans) < max_len:
            ans.append(nums[idx])
            idx = g[idx]
        ans.reverse()
        return ans
