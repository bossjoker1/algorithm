# 感觉题解好绕...
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)

        # 边界情况，当没有石子时，分数为 0
        f = [-10**9] * n + [0]
        for i in range(n - 1, -1, -1):
            pre = 0
            for j in range(i + 1, min(i + 3, n) + 1):
                pre += stoneValue[j - 1]
                f[i] = max(f[i], pre - f[j])
        
        if f[0] == 0:
            return "Tie"
        else:
            return "Alice" if f[0] > 0 else "Bob"