//感觉还可以优化为一维数组
//多括一行一列则不用考虑边界问题（在这没实现
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0&&j!=0)
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                else if(i!=0&&j == 0)
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                else if(i != 0 && j != 0)
                    dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]) ;
            }
        }

        return dp[m-1][n-1];

    }
};