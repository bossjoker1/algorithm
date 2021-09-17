/*状态转移方程
*base case:  dp[-1][k][0] = dp[i][0][0] = 0
*            dp[-1][k][1] = dp[i][0][1] = INT_MIN
*else:       dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + price[i])
*            dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - price[i])
*
*/
/*由上述方程知需要构建三维数组，又因为最多只需要n/2次，所以空间复杂度为O(n^2)*/
class Solution {
public:
    int maxProfit_inf(vector<int>& prices) {
        int dp_0 = 0, dp_1 = INT_MIN;
        int n = prices.size();
        for( int i = 0; i < n ; i++){
            int temp = dp_0;
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, temp - prices[i]);
        }
        return dp_0;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //此时跟 k = infinity 的情况一样。
        if(k > n/2) return maxProfit_inf(prices);
        //初始化三维vector数组
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2)));
        for(int i = 0; i < n;i++){
            //base case1
            dp[i][0][0] = 0; dp[i][0][1] = INT_MIN;
            for(int ki = k; ki > 0;ki--){
                //base case2
                if( i == 0 ) {dp[i][ki][0] = 0; dp[i][ki][1] = -prices[i]; continue;}
                dp[i][ki][0] = max(dp[i-1][ki][0], dp[i-1][ki][1] + prices[i]);
                dp[i][ki][1] = max(dp[i-1][ki][1], dp[i-1][ki-1][0] - prices[i]);
            }
        }
        return dp[n-1][k][0];
    }
};
