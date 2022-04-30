class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        # 思路：统计以当前字母结尾的字串，注意是取最大值，否则会重复
        cnt = [0] * 26
        cur = 1
        for i in range(0, len(p)):
            # 是连续的
            if i > 0 and (ord(p[i-1]) - ord('a') + 1) % 26 == (ord(p[i]) - ord('a')) % 26:
                cur += 1
            else:
                cur = 1

            idx = ord(p[i]) - ord('a')
            cnt[idx] =  max(cnt[idx], cur)

        return sum(cnt)