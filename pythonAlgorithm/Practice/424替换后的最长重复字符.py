class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        nums = [0] * 26
        n = len(s)
        l, r, maxn = 0, 0, 0
        while r < n:
            nums[ord(s[r]) - 65] += 1
            maxn = max(maxn,  nums[ord(s[r]) - 65])

            if r - l + 1 - maxn > k:
                nums[ord(s[l]) - 65] -= 1
                l += 1

            r += 1

        return r - l

