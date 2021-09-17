class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //k=2,情况较少直接全写出来
        int dp_10 = 0, dp_11 = INT_MIN;
        int dp_20 = 0, dp_21 = INT_MIN;
        for(auto price: prices){
            dp_10 = max(dp_10, dp_11 + price);
            dp_11 = max(dp_11, -price);
            dp_20 = max(dp_20, dp_21 +price);
            dp_21 = max(dp_21, dp_10 - price);
        }
        return dp_20;
    }
};