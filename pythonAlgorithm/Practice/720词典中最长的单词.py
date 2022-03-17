# 加set，然后对每个单词，匹配其所有的前缀

class Solution:
    def longestWord(self, words: List[str]) -> str:
        prefix = set()
        res = ""
        for item in words:
            prefix.add(item)
        for item in words:
            flag = True
            for i in range(1, len(item)):
                if item[:i] not in prefix:
                    flag = False
                    break
            if flag:
                if len(item) > len(res):
                    res = item
                elif len(item) == len(res):
                    res = min(res, item)
        return res