class Solution:
    def trap(self, height: List[int]) -> int:
        res = 0
        n = len(height)
        if n == 0:
           return 0
        left, right = 0, n-1
        l_m, r_m = height[left], height[right]
        while left <= right:
            l_m = max(l_m, height[left])
            r_m = max(r_m, height[right])

            if l_m < r_m:
                res += l_m - height[left] 
                left += 1
            else:
                res += r_m - height[right]
                right -= 1
        return res 
    
