# 字符串+滑动窗口
# 注意左指针不要移得太快

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        cnt = Counter(s1)
        m, n = len(s1), len(s2)
        l, r = 0, 0

        k = 0
        mp = defaultdict(int)
        while r < n:
            if cnt[s2[r]] == 0:
                r += 1
                l = r
                mp.clear()
                k = 0
                continue

            mp[s2[r]] += 1
            k += 1

            while mp[s2[r]] > cnt[s2[r]]:
                mp[s2[l]] -= 1
                k -= 1
                l += 1

            if k >= m:
                # print(mp)
                return True

            r += 1

        return False