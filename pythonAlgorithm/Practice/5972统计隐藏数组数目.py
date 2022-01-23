class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        
        minv, maxv  = sys.maxsize, -sys.maxsize
        tsum = 0
        for i in differences:
            tsum += i
            minv = min(minv, tsum)
            maxv = max(maxv, tsum)
        
        res = (upper - max(0, maxv)) - (lower - min(0, minv)) + 1
            
                
        return res if res >= 0 else 0