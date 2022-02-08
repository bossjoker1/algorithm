# easy题
# hash表维护下计数就行
class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        numcnt, res = defaultdict(int), 0
        for item in nums:
            numcnt[item] += 1
            if item - k in numcnt:
                res += numcnt[item-k]
            if item + k in numcnt:
                res += numcnt[item+k]

        return res