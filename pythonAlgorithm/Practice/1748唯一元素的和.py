# 太水了
class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        cnt = [0]*101
        for item in nums:
            cnt[item] += 1
        res = 0
        for i in range(1, 101):
            if cnt[i] == 1:
                res += i

        return res
    
# 一次遍历算法

class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        cnt, res = [0]*101, 0
        for item in nums:
            if cnt[item] == 0:
                res += item
            if cnt[item] == 1:
                res -= item
            cnt[item] += 1

        return res