# sb题目
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        # 判断本身是不是回文串
        l, r = 0, len(s) - 1
        while l < r and s[l] == s[r]:
            l, r = l + 1, r - 1
        return 2 if l < r else 1