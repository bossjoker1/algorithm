# 我的sb解法
# 因为python string 不可变所以必须得有个额外的结果数组
class Solution:
    def reverseWords(self, s: str) -> str:
        temp = s.split(' ')
        temp.reverse()
        temp = [x.strip() for x in temp if x.strip() != '']
        print(temp)
        return ' '.join(x for x in temp)

class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])
    
