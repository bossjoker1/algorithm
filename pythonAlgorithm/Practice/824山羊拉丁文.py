# 模拟
class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        s = sentence.strip().split(" ")
        k = 1
        res = []
        for item in s:
            temp = ""
            if item == "":
                continue
            if item[0].lower() in ['a', 'e', 'i', 'o', 'u']:
                temp = item
            else:
                temp = item[1:] + item[0]
            temp = temp + "ma" + "a" * k
            res.append(temp)
            k += 1

        return " ".join(res)