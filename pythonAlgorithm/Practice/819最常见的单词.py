# 使用带正则表达式匹配的split()方法
import re
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        l = re.split('[!?\',;.]|\s+',paragraph)
        hp = defaultdict(int)
        for item in l:
            if item:
                hp[item.lower()] += 1

        res, maxn = "", -1
        for k, v in hp.items():
            if maxn < v and k not in banned:
                maxn = v
                res = k

        return res
