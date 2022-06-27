# 映射到数组尾部，将数据类型区分
class Solution:
    def __init__(self, n: int, blacklist: List[int]):
        m = len(blacklist)
        self.bound = w = n - m
        black = {b for b in blacklist if b >= self.bound}
        self.b2w = {}
        for b in blacklist:
            if b < self.bound:
                while w in black:
                    w += 1
                self.b2w[b] = w
                w += 1

    def pick(self) -> int:
        x = randrange(self.bound)
        return self.b2w.get(x, x)


# Your Solution object will be instantiated and called as such:
# obj = Solution(n, blacklist)
# param_1 = obj.pick()