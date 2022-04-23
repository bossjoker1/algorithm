# 最终结果就是每个石头前面加 + / -
# 直接分析成01背包
# 而且实际分析时只需考虑一边

class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        n, s = len(stones), sum(stones)
        t = s // 2

        f = [0] * (t+1)

        for i in range(1, n+1):
            x = stones[i-1]
            for j in range(t, x-1, -1):
                f[j] = max(f[j], f[j - x] + x)

        return abs(s - f[t] - f[t])