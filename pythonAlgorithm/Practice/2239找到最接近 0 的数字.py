class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        res = 100005
        for i in nums:
            if abs(i) < abs(res) or (abs(i) == abs(res) and i > res):
                res = i
        return res
