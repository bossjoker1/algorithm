# 模拟题
class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        n = len(data)
        i = 0
        while i < n:
            if (data[i] >> 7) ^ 1:
                i += 1
            else:
                cnt = 0
                while (data[i] >> (7 - cnt)) & 1:
                    cnt += 1
                    if cnt > 4:
                        return False
                if cnt <= 1 or i + cnt > n:
                    return False
                for j in range(i+1, i+cnt):
                    if not ((data[j] >> 7) & 1 and (data[j] >> 6) ^ 1):
                        return False
                i += cnt

        return True