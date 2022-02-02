# 又是一天简单题
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        p = word.find(ch) 
        return word if p == -1 else word[p::-1] + word[p+1:] 