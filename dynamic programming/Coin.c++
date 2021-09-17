class Solution {
public:
    int waysToChange(int n) {
        int mod = 1000000007;
        //要按从小到大的顺序，否则会出现 1, 5, 1和5, 1, 1几种情况
        int coins[4] = {1, 5, 10, 25}; 
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int coin:coins){
            for(int i = coin; i <= n; i++){
                dp[i] = (dp[i] + dp[i - coin])%mod;
            }
        }
        return dp[n];
    }
};