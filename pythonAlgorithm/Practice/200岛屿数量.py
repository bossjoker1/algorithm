# 思路一：并查集
# class Solution {
# public:
#     int p[100000];

#     int finds(int x){
#         if (p[x] != x) p[x] = finds(p[x]);
#         return p[x];
#     }

#     int numIslands(vector<vector<char>>& grid) {
#         int n = grid.size(), m = grid[0].size();
#         for (int i = 1; i <= n*m; i ++) p[i] = i;
#         for (int i=0; i<n; i++){
#             for (int j=0; j<m; j++){
#                 int k = (m*i)+j+1;
#                 if (grid[i][j] == '1'){
#                     if (i-1 >= 0 && grid[i-1][j] == '1' && finds(k) != finds(k-m)) p[finds(k)] = finds(k-m);
#                     if (j-1 >= 0 && grid[i][j-1] == '1' && finds(k) != finds(k-1)) p[finds(k)] = finds(k-1);
#                 }
#                 else p[k] = 0;
#             }
#         }
#         int res = 0;

#         for (int i = 1; i <= n*m; i ++) {
#             if (p[i] == i) res ++;
#         }

#         return res;
        
#     }
# };


# 思路二：每一次dfs将所有能搜到的1都改为0，即一次清楚一个岛屿
# 之前自己写的c++代码：
# class Solution {
# public:

#     void dfs(vector<vector<char>>& grid,int x, int y){
#         grid[x][y] = '0';

#         if(x-1>=0&&grid[x-1][y] == '1') dfs(grid, x-1, y);
#         if(x+1<grid.size()&&grid[x+1][y] == '1') dfs(grid, x+1, y);
#         if(y-1>=0&&grid[x][y-1] == '1') dfs(grid, x, y-1);
#         if(y+1<grid[0].size()&&grid[x][y+1] == '1') dfs(grid, x, y+1);

#         return;

#     }

#     int numIslands(vector<vector<char>>& grid) {
#         int res = 0;
#         for(int i = 0;i < grid.size();i++){
#             for(int j = 0; j < grid[0].size();j++){
#                 if(grid[i][j] == '1'){
#                     dfs(grid, i, j);
#                     res ++;
#                 }
#             }
#         }
#         return res;
#     }
# };