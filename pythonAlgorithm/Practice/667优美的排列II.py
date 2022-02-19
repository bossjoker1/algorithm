# 交错排列最多为 n-1 个
# 顺序排列都为 1 
# 所以要得到k个，只需要 k 个交错排列， n - k 个顺序排列就行
class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        res = []
        # 前n-k个顺序排列
        for i in range(1, n-k):
            res.append(i)

        l, r = n - k, n
        for j in range(k+1):
            if  j % 2 == 0:
                res.append(l)
                l += 1
            else:
                res.append(r)
                r -= 1

        return res