# 两次遍历，求最小值
# 双指针
class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        l, r = 0, -1
        res = [10005] * n

        for i in range(n):
            if s[i] == c:
                r = i
            if r != -1:
                while l <= r:
                    res[l] = abs(l - r)
                    l += 1

        while l < n:
            res[l] = abs(l-r)
            l += 1
        l, r = n-1, n

        for i in range(n-1, -1, -1):
            if s[i] == c:
                r = i
            if r != n:
                while l >= r:
                    res[l] = min(res[l], abs(l - r))
                    l -= 1

        while l >= 0:
            res[l] = min(res[l], abs(l - r))
            l -= 1

        return res

# 精简版
# 上面我的代码有很多不必要的部分
class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        r = -1
        res = [10005] * n

        for i in range(n):
            if s[i] == c:
                r = i
            if r != -1:
                res[i] = abs(i - r)

        r = n
        for i in range(n-1, -1, -1):
            if s[i] == c:
                r = i
            if r != n:
                res[i] = min(res[i], abs(i - r))

        return res 