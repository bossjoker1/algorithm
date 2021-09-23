// 使用了比暴力nb一点点的dp
// 不过好歹完全自己想出来的法子，说实话我感觉还行
// 能过就行，执行用时：28 ms, 在所有 C++ 提交中击败了36.30% 的用户
class Solution {
public:

    // 设dp[i][j]=k 表示以(i, j)为右端点边长为k的正方形
    // 转移方程 matrix[i][j] = '1' => dp[i][j] = 1;
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0)); //初始化dp
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(matrix[i][j] == '1') { dp[i][j] = 1, res = 1;}
            }
        }
        // 第一行第一列边界可以跳过
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m ;j++){
                bool flag;
                if(dp[i][j]){
                    // 特别注意这层循环，即如果更大的正方形找不到，还必须判断小一些的能否满足
                    int count = dp[i-1][j-1];
                    while(count > 0){
                        flag = true;
                        for(int k = 1; k <= count; k++){
                            if(matrix[i][j-k] != '1' || matrix[i-k][j] != '1'){
                                flag = false;
                            }
                        }
                        if(flag) break;
                        count -- ;
                    }
                    // 状态转移
                    dp[i][j] = flag ? count + 1 : dp[i][j];

                    res = res < dp[i][j] ? dp[i][j] : res;
                }
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j< m; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return res*res;
    }


};


// 官方解答，dp含义是相同的，不过状态转移方程确实简单明了多了

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};
