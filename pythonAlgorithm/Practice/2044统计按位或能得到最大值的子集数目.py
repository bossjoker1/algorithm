class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        s = 1 << n
        res, cnt = 0, 0
        for mask in range(1, s):
            temp = 0
            for i in range(n):
                if (mask >> i) & 1:
                    temp |= nums[i]
            if temp > res:
                res = temp
                cnt = 1
            elif temp == res:
                cnt += 1

        return cnt
