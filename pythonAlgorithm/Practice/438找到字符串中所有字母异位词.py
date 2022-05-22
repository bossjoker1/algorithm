# 567 魔改一下就能过
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        cnt = Counter(p)
        m, n = len(p), len(s)
        l, r = 0, 0
        res = []
        k = 0
        mp = defaultdict(int)
        while r < n:
            if cnt[s[r]] == 0:
                r += 1
                l = r
                mp.clear()
                k = 0
                continue

            mp[s[r]] += 1
            k += 1

            while mp[s[r]] > cnt[s[r]]:
                mp[s[l]] -= 1
                k -= 1
                l += 1

            if k >= m:
                res.append(l)

            r += 1

        return res