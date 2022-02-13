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
    
# c++空间复杂度才能达到O(1)
# 思路是先去除左右空格和中间的多余空格
# 然后反转整个字符串再反转单词