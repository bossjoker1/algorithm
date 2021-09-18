// 大哥的解法，每走一格消耗一点"能量"，当前点就相当于补给兑换，如果自己的能量更多则不换，少则更新能量值
// O(n)
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if(nums.size() == 0)
            return true;

        int cur = nums[0], i = 1;
        for(; cur != 0 && i < nums.size(); i++)
        {
            cur--;
            if(cur < nums[i])
                cur = nums[i];
        }
        return i == nums.size();
    }
};

// 我的傻逼解法，搞个dp，复杂度提升到O(n^2) ，反倒陷进了dp套路里面了
// 成功在leetcode超时，事实证明O(n^2)在哪里都不保险

public:
    bool canJump(vector<int>& nums) {
        // dp[i]表示第i个位置能否达到
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true; // 下标0肯定能达到
        for(int i = 0; i < n-1;i++){
            int skip = nums[i];
            if(nums[i]==0) continue;
            if(dp[i]){
                for(int j = 1; j <= skip; j++){
                    if(i+j>=n-1){
                        return true;
                    }
                    dp[i+j] = true;
                }
            }
        }
        return dp[n-1];
    }
};