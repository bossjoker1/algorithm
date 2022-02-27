class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        
        def check(cur:int)-> bool:
            cnt = 0
            for i in range(len(time)):
                cnt += cur // time[i]
                
                if cnt >= totalTrips:
                    return True
                
            if cnt < totalTrips:
                return False
                
        time.sort()
        
        l, r = 1, time[0] * totalTrips
        
        while l < r:
            mid  = (l + r) >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
                
        return l