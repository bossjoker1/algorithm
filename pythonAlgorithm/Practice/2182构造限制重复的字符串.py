# 学习Counter 和 heapq
# 贪心
class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        cnt = Counter(s)
        h = []
        for key in cnt.keys():
            heapq.heappush(h, [-ord(key), cnt[key]])

        ans = ""

        while h:
            cur = heapq.heappop(h)

            if cur[1] <= repeatLimit:
                ans += chr(-cur[0]) * cur[1]
            else:
                ans += chr(-cur[0]) * repeatLimit
                cur[1] -= repeatLimit

                if h:
                    # 如果还有就可以用下一个元素出一个做间隔
                    # 此时大的才能加回到堆里
                    cur2 = heapq.heappop(h)
                    ans += chr(-cur2[0])
                    cur2[1] -= 1
                    heapq.heappush(h, cur)
                    if cur2[1]>0:
                        heapq.heappush(h, cur2)

        return ans


