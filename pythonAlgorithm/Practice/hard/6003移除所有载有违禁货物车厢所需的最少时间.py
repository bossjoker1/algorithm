# 提示说维护两个数组，后缀对应排除左移，前缀对应排除右移
# 两个合并考虑，应该能做

class Solution:
    def minimumTime(self, s: str) -> int:
        n = len(s)
        post, pre = [0] * (n+1), 0
        # 维护后缀dp
        for i in range(n-1, -1, -1):
            if s[i] == "0":
                post[i] = post[i+1]
            else:
                post[i] = min(post[i+1]+2, n-i)
        # 维护前缀dp
        # 滚动数组优化
        minv = post[0]
        for i in range(n):
            pre = min(pre+2, i+1)
            minv = min(minv, pre + post[i+1])
        return minv
    
# 将移除某些中间的车厢可以合并到一边
# 前缀和可以用滚动数组优化，合并到它中
class Solution:
    def minimumTime(self, s: str) -> int:
        ans = n = len(s)
        pre = 0
        for i, ch in enumerate(s):
            if ch == '1':
                pre = min(pre + 2, i + 1)
            ans = min(ans, pre + n - 1 - i)
        return ans

