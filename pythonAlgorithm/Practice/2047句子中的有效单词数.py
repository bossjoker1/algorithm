# sb模拟
class Solution:
    def countValidWords(self, sentence: str) -> int:
        res = 0
        sign = ['!', '.', ',']
        strArr = sentence.split(' ')
        for s in strArr:
            if s == '': continue
            i, flag, cnt = 0, True, 0
            while i < len(s):
                if 48 <= ord(s[i]) <= 57:
                    flag = False
                    break
                if s[i] in sign and i != len(s)-1:
                    flag = False
                    break
                if s[i] in sign and cnt > 0:
                    if s[i-1] == '-':
                        flag = False
                        break
                if s[i] == '-':
                    if cnt > 0 or (i == 0 or i == len(s)-1):
                        flag = False
                        break
                    else:
                        cnt += 1
                i+=1
            if flag:
                res += 1
                print(s)

        return res
                

# 正则匹配
import re
class Solution:
    def countValidWords(self, sentence: str) -> int:
        arr = sentence.split()
        cnt = 0

        for word in arr:
            # 两种匹配模式，「 | 」 左边为有连接号的更长匹配，右边仅为单词与标点符号的匹配
            p = re.match(r'[a-z]+-?[a-z]+[!.,]?|[a-z]*[!.,]?', word)
            if p and p.group(0) == word:
                cnt += 1
        
        return cnt
