# 找到1所在的位置
class Solution:
    def binaryGap(self, n: int) -> int:
        res = []
        while n:
            res.append(len(bin(n &(-n))))
            n -= n &(-n)

        if len(res) <= 1:
            return 0
        else:
            pre, maxn = res[0], 0
            for i in range(1, len(res)):
                maxn = max(maxn, res[i] - pre)
                pre = res[i]
            return maxn

# 写复杂了，淦~
class Solution:
    def binaryGap(self, n: int) -> int:
        ans = 0
        j = -1
        for i in range(31, -1, -1):
            if (n>>i) & 1:
                if j != -1:
                    ans = max(ans, abs(j - i))
                j = i

        return ans