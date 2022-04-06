# 二分，注意指针的移动
class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        s = sum(candies)
        if k > s:
            return 0
               
        r = s // k
        l = 1
        while l <= r:
            mid = (l + r) >> 1
            cnt = 0
            for x in candies:
                cnt += x // mid
            if cnt >= k:
                l = mid + 1
            else:
                r = mid - 1
        
        return r