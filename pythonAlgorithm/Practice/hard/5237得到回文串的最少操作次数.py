# tip: 贪心地匹配最左边(如何做到最小步数？)
# 找与左边一致的最靠近右边的，如果没有说明是要放在中间的
class Solution:
    def minMovesToMakePalindrome(self, s: str) -> int:
        if not s: return 0
        cnt, n = 0, len(s)
        temp = ""
        for i in range(n-1, -1, -1):
            if s[0] == s[i] and i != 0:
                temp = s[1:i] + s[i+1:]
                cnt += n - i - 1
                break
            if i==0:
                cnt += n // 2
                temp = s[1:]

        return cnt + self.minMovesToMakePalindrome(temp)
        