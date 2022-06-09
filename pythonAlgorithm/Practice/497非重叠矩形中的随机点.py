# 前缀和
# 随机的范围是整个点的数量
# 根据值确定是在哪个矩形，然后根据矩形长宽，将点的值转为行和列

class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.presum = [0]
        for a, b, x, y in rects:
            self.presum.append(self.presum[-1] + (x - a + 1) * (y - b + 1))

    def pick(self) -> List[int]:
        rdm = random.randint(0, self.presum[-1] - 1)
        idx = bisect_right(self.presum, rdm) - 1
        a, b, x, y = self.rects[idx]
        v = rdm - self.presum[idx]
        return [a + v % (w := x - a + 1), b + v // w]

# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()

