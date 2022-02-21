# 之前做过了, 分状态写的
# 双指针
# dl的解法是记录该点到左边R的距离和到右边L的距离，哪个近就往同侧倒，一样就不倒

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        # [L_dist, R_dist]
        records = [[inf, inf] for _ in range(n)]
        cur = -inf
        for i, c in enumerate(dominoes):
            if c == 'R':
                cur = i
            elif c == 'L':
                cur = -inf
            records[i][1] = i - cur
        cur = inf
        for i in range(n - 1, -1, -1):
            if dominoes[i] == 'L':
                cur = i
            elif dominoes[i] == 'R':
                cur = inf
            records[i][0] = cur - i
        return "".join('.' if l == r else ('R' if l > r else 'L') for l, r in records)

