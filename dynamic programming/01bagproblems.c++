//简单而又经典的01背包问题
//核心代码
//dp[i][w]表示：对于前i个物品，当前背包的容量为w时，所能装下的最大价值，所以最后返回的就是dp[N][W]
for (int  i = 0; i < N; i++)
{
    for(int w = 1;w<=W;w++){
        if(w - wt[i] < 0) dp[i][w] = dp[i-1][w];
        else 
            dp[i][w] = max(dp[i-1][w-wt[i-1]] + val[i-1], dp[i-1][w]);
    }
}


//416. Partition Equal Subset Sum
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sums = 0, n = nums.size();
        for(int num: nums) sums+=num;
        if((sums % 2) != 0) return false;
        sums /= 2;
        vector<bool> dp(sums+1,false);
        dp[0] = true; //base case
        for(int i = 0;i < n;i++){
            for(int j = sums; j>=1;j--){
                if(j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sums];
    }
};
