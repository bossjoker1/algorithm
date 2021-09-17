class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>> &dp, int i, int j){
        int n = dp.size(), m = dp[0].size();
        res.push_back({i, j});
        //结束条件
        if(i == n-1 && j = m -1) return;
        //题目只需找一个解，所以我们只往可行的一个方向移动就行。
        if(i < n-1 && dp[i+1][j] == 0) dfs(dp, i+1, j);
        else if(j < m-1 && dp[i][j+1] == 0) dfs(dp, i, j+1);
        //return; 
    }

    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        //奇怪的输入
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return {};
        vector<vector<int>> dp = obstacleGrid;
        //状态取决于后者，故从大到小
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j>= 0; j--){
                //边界条件
                if(dp[i]dp[j]==1||(i == n-1&&j == m-1)) continue;
                if( i == n-1) dp[i][j] = dp[i][j+1];
                else if( j == m-1) dp[i][j] = dp[i+1][j];
                else dp[i][j] = dp[i+1][j]&dp[i][j+1];
            }
        }
        if(dp[0][0] == 1) return {};
        dfs(dp, 0, 0);
        return res;
    }
};