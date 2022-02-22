# 区间dp，之前刷csp时都只做过几题类似的...

# 模板，O(n^3)，不出意外的超时了
class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        presum = [0]*(n+1)
        for i in range(n):
            presum[i+1] = presum[i] + stoneValue[i]

        f = [[0] * n for _ in range(n)]

        # 先枚举长度，再枚举起点，最后枚举切分点
        # 故时间复杂度为O(n^3)

        # 分段长度d
        for d in range(2, n + 1):
            # 起点i
            for i in range(n - d + 1):
                # 终点j
                j = i + d - 1

                for k in range(i, j):
                    left = presum[k+1] - presum[i]
                    right = presum[j+1] - presum[k+1]

                    # 状态转移
                    # 因为题意Bob为让Alice得到小的那行，所以应该有和小的那边转移过来
                    if left > right:
                        f[i][j] = max(f[i][j], right + f[k+1][j])
                    elif left < right:
                        f[i][j] = max(f[i][j], left + f[i][k])
                    else:
                        # 相等的话，需要选更大的分数
                        f[i][j] = max(f[i][j], right + f[k+1][j], left + f[i][k])

        return f[0][n-1]
    
# 优化到O(n^2)，贴个题解，这不可能想出来的...
class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        f = [[0] * n for _ in range(n)]
        maxl = [[0] * n for _ in range(n)]
        maxr = [[0] * n for _ in range(n)]

        for left in range(n - 1, -1, -1):
            maxl[left][left] = maxr[left][left] = stoneValue[left]
            total = stoneValue[left]
            suml = 0
            i = left - 1
            for right in range(left + 1, n):
                total += stoneValue[right]
                while i + 1 < right and (suml + stoneValue[i + 1]) * 2 <= total:
                    suml += stoneValue[i + 1]
                    i += 1
                if left <= i:
                    f[left][right] = max(f[left][right], maxl[left][i])
                if i + 1 < right:
                    f[left][right] = max(f[left][right], maxr[i + 2][right])
                if suml * 2 == total:
                    f[left][right] = max(f[left][right], maxr[i + 1][right])
                maxl[left][right] = max(maxl[left][right - 1], total + f[left][right])
                maxr[left][right] = max(maxr[left + 1][right], total + f[left][right])
        
        return f[0][n - 1]


