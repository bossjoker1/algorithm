// 200 middle 并查集里面的，但感觉这题用并查集没优化多少，所以就用dfs跑了算了
class Solution {
public:

    void dfs(vector<vector<char>>& grid,int x, int y){
        grid[x][y] = '0';

        if(x-1>=0&&grid[x-1][y] == '1') dfs(grid, x-1, y);
        if(x+1<grid.size()&&grid[x+1][y] == '1') dfs(grid, x+1, y);
        if(y-1>=0&&grid[x][y-1] == '1') dfs(grid, x, y-1);
        if(y+1<grid[0].size()&&grid[x][y+1] == '1') dfs(grid, x, y+1);

        return;

    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    res ++;
                }
            }
        }
        for(int i = 0;i < grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return res;
    }
};