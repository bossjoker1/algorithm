# 双周赛压轴题
# hard ：二维前缀和 + 二维差分数组
class Solution:
    def possibleToStamp(self, grid: List[List[int]], stampHeight: int, stampWidth: int) -> bool:
        m, n = len(grid), len(grid[0])
        # 开大点便于处理边界情况
        sum = [[0] * (n + 1) for _ in range(m + 1)]
        diff = [[0] * (n + 2) for _ in range(m + 2)]

        for i, row in enumerate(grid):
            for j, v in enumerate(row):  # grid 的二维前缀和
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + v

        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if v == 0:
                    x, y = i + stampHeight, j + stampWidth  # 注意这是矩形右下角横纵坐标都 +1 后的位置
                    if x <= m and y <= n and sum[x][y] - sum[x][j] - sum[i][y] + sum[i][j] == 0:
                        diff[i+1][j+1] += 1
                        diff[i+1][y+1] -= 1
                        diff[x+1][j+1] -= 1
                        diff[x+1][y+1] += 1  # 更新二维差分
        # 单点查询
        # 差分数组累加
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                diff[i+1][j+1] += diff[i][j+1] + diff[i+1][j] - diff[i][j]
                # 该点没有被任何邮票覆盖到
                if v == 0 and diff[i+1][j+1] == 0:
                    return False
        return True

# c++ 版本
# class Solution {
# public:
#     bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
#         int n = grid.size(), m = grid[0].size();
#         vector<vector<int>> sums(n + 1, vector<int>(m + 1)); // 前缀和数组用于检查是否能放
#         vector<vector<int>> diff(n + 2, vector<int>(m + 2)); // 差分数组用于标记放置点
        
#         for(int i = 1; i <= n; ++i) // 初始化前缀和数组
#             for(int j = 1; j <= m; ++j)
#                 sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + grid[i - 1][j - 1];
        
#         for(int i = h; i <= n; ++i) // 利用差分标记可放置的点
#         {
#             for(int j = w; j <= m; ++j)
#             {
#                 int x = sums[i][j] - sums[i - h][j] - sums[i][j - w] + sums[i - h][j - w];
#                 if(x == 0) // 可以放置
#                 {
#                     ++diff[i - h + 1][j - w + 1];
#                     --diff[i - h + 1][j + 1];
#                     --diff[i + 1][j - w + 1];
#                     ++diff[i + 1][j + 1];
#                 }
#             }
#         }
        
#         // 利用前缀和 与 差分数组还原出填充的数组
#         for(int i = 1; i <= n; ++i)
#         {
#             for(int j = 1; j <= m; ++j)
#             {
#                 diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
#                 if(grid[i - 1][j - 1]) continue;
#                 if(diff[i][j] == 0)
#                     return false;
#             }
#         }

#         return true;
#     }
# };
