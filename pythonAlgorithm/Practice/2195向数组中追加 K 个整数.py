class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        nums.sort()
        cnt, res = 0, 0
        left = 0
        for item in nums:
            if cnt == k:
                break
            if item > (left + 1):
                temp = min(item - left - 1, k - cnt)
                cnt += temp
                res += (left + 1 + left + temp) * temp // 2
            left = item
        
        if cnt < k:
            res += (nums[-1] + 1 + nums[-1]  + k - cnt) * (k - cnt) // 2
        
        return res