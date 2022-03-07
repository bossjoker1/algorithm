# 自定义排序即可
class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:

        def trans(num):  
            if not num: return mapping[0] #注意对0需要特判，否则会把0转换成0      
            ans = 0
            times = 1
            while num:
                cur = num%10
                ans+=mapping[cur]*times
                times*=10
                num//=10
            return ans
        
        return sorted(nums,key=trans)  
