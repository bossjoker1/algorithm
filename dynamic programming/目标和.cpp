// 分为两个子集，转化为01背包问题
// 这里选择负数集 neg = (sum - target) / 2;   => sum >= target && (sum-target)%2 == 0
// dp[j] 表示负数集的和为j的种类数

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum - target < 0 || (sum - target)%2 != 0){
            return 0;
        }
        int neg = (sum - target) / 2;
        vector<int> dp(neg + 1);
        dp[0] = 1;
        for(auto & num : nums){
            for(int j = neg; j >= num; j--){
                dp[j] += dp[j - num];
            }
        }

        return dp[neg];
    }
};