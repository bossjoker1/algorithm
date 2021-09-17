// 零和博弈  区间dp问题
// dp[i][j]表示当前先手（注意是当前先手，即前一个后手在当前又是先手）与另一个玩家的最大差值
// 显然dp[i][i] = nums[i]
// dp[i][j] = max(nums[i] - dp[i+1][j], nums[j]-dp[i][j-1])
// 所以j > i，即状态转移是一个上三角矩阵，且可以由一维数组表示
// 如果是偶数个，则先手可以计算偶数列和奇数列，则他可以保证拿和更大的列，所以一定会赢
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int length = nums.size();
        auto dp = vector<vector<int>> (length, vector<int>(length));
        for (int i = 0; i < length; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = length - 2; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][length - 1] >= 0;
    }
};


//路径压缩
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int length = nums.size();
        if(length%2==0) return true;
        auto dp = vector<int>(length);
        for (int i = 0; i < length; i++) {
            dp[i] = nums[i];
        }
        for (int i = length - 2; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[length - 1] >= 0;
    }
};