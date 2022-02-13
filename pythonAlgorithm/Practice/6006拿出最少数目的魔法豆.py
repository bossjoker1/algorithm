# 感觉比较简单
# 不需要dp
class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        beans.sort()
        n, s = len(beans), sum(beans)
        if n <= 1:
            return 0
        minv = s - beans[0] * n
        for i in range(1, n):
            # 清空或者不清空
            minv = min(minv, s - beans[i] * (n-i))
            
        return minv
            