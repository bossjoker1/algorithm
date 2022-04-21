class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        # 贪心，首先肯定要第一列都是1
        res = m * (1 << (n-1))

        # 对除第一列之外的每一列 "1"要尽可能多
        for i in range(1, n):
            cnt = 0
            for j in range(m):
                if grid[j][0] == 1:
                    # 没有行翻转
                    cnt += grid[j][i]
                else:
                    cnt += 1 - grid[j][i]

            k = max(cnt, m - cnt)

            res += k * (1 << (n - 1 - i))

        return res 
