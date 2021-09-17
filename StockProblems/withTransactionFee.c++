class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp_0 = 0, dp_1 = INT_MIN;
        int n = prices.size();
        for( int i = 0; i < n ; i++){
            int temp = dp_0;
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, temp - prices[i] - fee);
        }
        return dp_0;
    }
};