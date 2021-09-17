// 300
// 考虑状态转移方程
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        vector<int> dp(len, 1); //base case
        for(int i = 0;i<len;i++){
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i])
                    dp[i] =max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

//二分搜索
//定义dp[i]: 长度为i+1的上升子序列中末尾元素的最小值(不存在则为INT_MAX)
//O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        fill(dp, dp+n, INT_MAX);
        for(int i = 0; i < n; i++){
            *lower_bound(dp, dp+n, nums[i]) = nums[i];
        }
        return lower_bound(dp, dp+n, INT_MAX) - dp;
    }
};