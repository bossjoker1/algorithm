// 三指针法

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        int a =1,  b =1,  c = 1;
        for(int i = 2; i <= n; i++){
            int m = min(min(dp[a]*2, dp[b]*3), dp[c]*5);
            dp[i] = m;
            if(m == dp[a]*2) a++;
            if(m == dp[b]*3) b++;
            if(m == dp[c]*5) c++;
            // cout<<dp[i]<<endl;
        }
        return dp[n];
    }
};