class Solution:
    def splitArraySameAverage(self, nums: [int]) -> bool:
        n = len(nums)
        nums_mean = mean(nums)
        @lru_cache(None)
        def dfs(i, total, cnt, sum):
            flag = False
            if total == cnt and sum/cnt == nums_mean:
                flag = True
            if i < n and cnt < total:
                for k in range(i, n):
                    flag = flag or dfs(k+1, total, cnt+1, sum+nums[k])
            return flag

        for cnt in range(1, n//2+1):
            if nums_mean * cnt - int(nums_mean * cnt) > 1e-9:
                continue
            if dfs(0, cnt, 0, 0):
                return True
        return False
