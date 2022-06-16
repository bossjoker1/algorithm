# 桶排序
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        bucket = [0] * 101
        for h in heights:
            bucket[h] += 1
        res = 0
        j = 0
        for i in range(1, 101):
            while bucket[i] > 0:
                if heights[j] != i:
                    print(i, heights[j])
                    res += 1
                j += 1
                bucket[i] -= 1
        return res