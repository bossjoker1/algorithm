# 滑动窗口 + 双指针

class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        n = len(answerKey)

        # 转化为求满足'T'或'F'数量不超过k的滑动窗口的最大长度
        def getCnt(c:str) -> int:
            ans = 0
            j, cnt = 0, 0
            for i in range(n):
                if answerKey[i] == c:
                    cnt += 1
                while cnt > k:
                    if answerKey[j] == c:
                        cnt -= 1
                    j += 1

                ans = max(ans, i - j + 1)

            return ans

        return max(getCnt('T'), getCnt('F'))

# 更nb点的解法
# 直接对计数较小的进行修改
class Solution:
    def maxConsecutiveAnswers(self, a: str, k: int) -> int:
        m, l, ans = defaultdict(int), 0, 0
        for r in range(len(a)):
            m[a[r]] += 1
            if min(m["T"], m["F"]) > k:
                m[a[l]] -= 1
                l += 1
        return r - l + 1