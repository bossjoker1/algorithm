# 麻了，周赛没做出来，总感觉有思路
# 前缀和，每一个点枚举4种L型

c25 = [[0]*2 for _ in range(1005)]

for i in range(2, 1001):
    if i % 2 == 0:
        c25[i][0] = c25[i//2][0] + 1
    if i % 5 == 0:
        c25[i][1] = c25[i//5][1] + 1

class Solution:
    def maxTrailingZeros(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        if m == 0:
            return 0
        row2 = [[0]*(n+1) for _ in range(m+1)]
        col2 = [[0]*(n+1) for _ in range(m+1)]
        row5 = [[0]*(n+1) for _ in range(m+1)]
        col5 = [[0]*(n+1) for _ in range(m+1)]

        ans = 0
        # 准备前缀和
        for i in range(1, m+1):
            for j in range(1, n+1):
                c2, c5 = c25[grid[i-1][j-1]]

                row2[i][j] = row2[i][j-1] + c2
                col2[i][j] = col2[i-1][j] + c2
                row5[i][j] = row5[i][j-1] + c5
                col5[i][j] = col5[i-1][j] + c5

        for i in range(1, m+1):
            for j in range(1, n+1):
                # 左上
                ans = max(ans, min(row2[i][j] + col2[i-1][j],row5[i][j] + col5[i-1][j] ))
                # 左下
                ans = max(ans, min(row2[i][j] + col2[m][j] - col2[i][j],row5[i][j] + col5[m][j] - col5[i][j] ))
                # 右上
                ans = max(ans, min(row2[i][n] - row2[i][j] + col2[i][j],row5[i][n] - row5[i][j] + col5[i][j] ))
                # 右下
                ans = max(ans, min(row2[i][n] - row2[i][j] + col2[m][j] -  col2[i-1][j],row5[i][n] - row5[i][j] + col5[m][j] - col5[i-1][j] ))


        return ans
                