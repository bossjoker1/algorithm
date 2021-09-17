class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = 0, dp_1 = INT_MIN;
        int n = prices.size();
        for( int i = 0; i < n ; i++){
            int temp = dp_0;
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, temp - prices[i]);
        }
        return dp_0;
    }
};

// with cooldown
//dp[i][0] = max(dp[i-1][0],dp[i-1][1] + price)
//dp[i][1] = max(dp[i-1][1],dp[i-2][0] - price)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = 0, dp_1 = INT_MIN;
        int n = prices.size();
        int pre = 0;
        for( int i = 0; i < n ; i++){
            int temp = dp_0;
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, pre - prices[i]);
            pre = temp;//取[i-2]
        }
        return dp_0;
    }
}; 
