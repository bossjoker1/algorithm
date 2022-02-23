# python 字符串不可变，可以将其转为list后再用双指针解题

class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        chars = list(s)
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not ( ord("A")<=ord(s[l])<=ord("Z") or ord("a")<=ord(s[l])<=ord("z")):
                l += 1

            while l < r and not ( ord("A")<=ord(s[r])<=ord("Z") or ord("a")<=ord(s[r])<=ord("z")):
                r -= 1

            if l < r:
                chars[l], chars[r] = chars[r], chars[l]
                l, r = l + 1, r - 1

        return "".join(chars)