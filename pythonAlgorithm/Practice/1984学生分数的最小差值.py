class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        minv, n = 100005, len(nums)
        for i in range(n-k+1):
            minv = min(minv, nums[i+k-1] - nums[i])

        return minv