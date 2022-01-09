class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, right = 0, 0
        maxn = 0
        i = 0 
        while i < len(s):
            if s[i] not in s[left:right]:
                right = right + 1
                if i == len(s) - 1:
                    maxn = max(maxn, right - left)
            else:
                maxn = max(maxn, right - left)
                left = left + 1
                i = i - 1
            i = i + 1

        return maxn