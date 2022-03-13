class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        s = set()
        n = len(nums)
        for i  in range(len(nums)):
            if nums[i] == key:
                for j in range(max(0, i-k), min(n, i+k+1)):
                    s.add(j)
                    
        return list(s)
                    