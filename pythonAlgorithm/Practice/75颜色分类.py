class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        cnt = [0] * 3
        for item in nums:
            cnt[item] += 1
        c = 0
        for i in range(3):
            for j in range(cnt[i]):
                nums[c] = i
                c += 1
