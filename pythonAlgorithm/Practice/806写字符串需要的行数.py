class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        cnt = 0
        res = 1
        for i in range(len(s)):
            temp = widths[ord(s[i]) - ord('a')] 
            if cnt + temp > 100:
                cnt = temp
                res += 1
            else:
                cnt += temp
        return [res, cnt]