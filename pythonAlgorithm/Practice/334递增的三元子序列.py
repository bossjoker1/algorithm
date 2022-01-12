# sb贪心即可

MAXN = 2**31
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        first, second = MAXN, MAXN
        for item in nums:
            if item <= first:
                first = item
            elif item <= second:
                second = item
            else:
                return True 
        return False



