class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        dic = {}
        l1, l2 = s1.split(' '), s2.split(' ')
        for item in l1:
            if item not in dic:
                dic[item] = 1
            else:
                dic[item] += 1

        for item in l2:
            if item not in dic:
                dic[item] = 1
            else:
                dic[item] += 1

        res = []

        for k, v in dic.items():
            if v == 1:
                res.append(k)

        return res
