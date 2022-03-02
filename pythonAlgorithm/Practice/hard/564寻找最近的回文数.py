# 长度为1直接返回 n-1
# 取前一半加1或者减1然后翻转
# 开头为1或者为9的特殊情况，已经对称或者本身不对称的情况
# 99 -> 101 ; 101 -> 99
# 将所有结果加入后，比较最小值

class Solution:
    def nearestPalindromic(self, n: str) -> str:
        if len(n) == 1:
            return str(int(n) - 1)
        l = len(n)
        half, v, ov = n[:l//2], int(n[:(l+1)//2]), int(n)
        res = set()
        s1, s2 = str(v-1), str(v + 1)
        res.add("9" * (l - 1))
        res.add("1" + "0" * (l - 1) + "1")
        if l % 2:
            res.add(s1[:-1] + s1[-1] + s1[:-1][::-1])
            res.add(s2[:-1] + s2[-1] + s2[:-1][::-1])
        else:
            res.add(s1 + s1[::-1])
            res.add(s2 + s2[::-1])
        if n[::-1] != n:
            res.add(half + n[l//2] + half[::-1] if l % 2 else half + half[::-1])
        if n in res:
            res.remove(n)
        return min(res, key = lambda x:(abs((k:=int(x)) - ov), k))
