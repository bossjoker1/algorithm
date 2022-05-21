class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        n = len(nums) // 2
        mp = defaultdict(int)
        for i in nums:
            mp[i] += 1
            if mp[i] == n:
                return i