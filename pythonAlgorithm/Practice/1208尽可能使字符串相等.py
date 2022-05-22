# 开始想成最长公共子序列了，心想不是得O(n^2)
# 但这题位置定死了，所以算很简单的滑动窗口了
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        n = len(s)
        maxn = 0
        l, r = 0, 0
        cnt = 0
        while r < n:
            cnt += abs(ord(t[r]) - ord(s[r]))

            while cnt > maxCost:
                cnt -= abs(ord(t[l]) - ord(s[l]))
                l += 1

            maxn = max(maxn, r - l + 1)

            r += 1

        return maxn