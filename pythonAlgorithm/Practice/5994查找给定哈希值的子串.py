# 278周赛 3 应该能走出来的wuwuwu
# 从后往前算
# 这样每次遍历，先乘以power再加上左边新的，减去最右边的
class Solution:
    def subStrHash(self, s: str, power: int, m: int, k: int, hashValue: int) -> str:
        
        h, p, index = 0, 1, len(s)-k
        for i in range(len(s)-1, index-1, -1):
            h =  (h * power + ord(s[i]) - 96) % m
            p = p * power % m
            
        for i in range(len(s)-k-1, -1, -1):
            h = (h * power + ord(s[i]) - 96 - (ord(s[i+k]) - 96) * p % m + m) % m
            if h == hashValue:
                index = i
        return s[index:index+k]