# 第300道题了！！！
# 状态压缩，同时dict{}维护state实现记忆化
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        s = sum(nums)
        if s % k != 0:#如果不能平分为k个集合的话,直接返回False
            return False 
        q = s // k  #每个集合的总和
        l = len(nums)
        def dfs(state, n, c):
            if state in cache:
                return cache[state]
            if c == k:
                cache[state] = True
                return True
            for i in range(l):
                if (state >> i) & 1 == 0:
                    res = dfs(state | 1 << i, n + nums[i], c) if n + nums[i] < q else dfs(state | 1 << i, 0, c + 1) if n + nums[i] == q else False #如果总和 + 插入的数字 大于单集合总和则不需要继续向下深搜
                    if res:
                        cache[state] = True
                        return True
            cache[state] = False
            return False
        cache = {}
        return dfs(0, 0, 0) 
