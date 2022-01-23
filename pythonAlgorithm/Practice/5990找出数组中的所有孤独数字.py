# 还是水题
class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        cnt = [0]*1000005
        
        for i in nums:
            cnt[i] += 1
        res = []    
        for i in nums:
            if i == 0:
                if cnt[0] == 1 and cnt[1] == 0:
                    res.append(i)
            else:
                if cnt[i] == 1 and not cnt[i-1] and not cnt[i+1]:
                    res.append(i)
                    
        return res
                
            