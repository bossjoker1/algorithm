class Solution:
    def arrayChange(self, nums: List[int], operations: List[List[int]]) -> List[int]:
        mp = defaultdict(int)
        n = len(nums)
        for i in range(n):
            mp[nums[i]] = i
            
        for k, v in operations:
            nums[mp[k]] = v
            
            mp[v] = mp[k]
            
        return nums