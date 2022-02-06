# 水题
class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        odd, even = [], []
        for i in range(len(nums)):
            if i % 2 == 0:
                even.append(nums[i])
            else:
                odd.append(nums[i])

        odd.sort(reverse=True)
        even.sort()
        res = []
        for i in range(len(even)):
            res.append(even[i])
            if i < len(odd):
                res.append(odd[i])

        return res
