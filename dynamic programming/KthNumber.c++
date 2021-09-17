//这动态规划是没想到的，太强了

class Solution {
public:
    int getKthMagicNumber(int k) {
        int p3=0, p5=0, p7=0;
        vector<int> dp(k, 0);
        dp[0] = 1;
        for(int i = 1; i< k;i++){
            dp[i] = min(dp[p3]*3, min(dp[p5]*5, dp[p7]*7));
            if(dp[i] == dp[p3]*3) p3++;
            if(dp[i] == dp[p5]*5) p5++;
            if(dp[i] == dp[p7]*7) p7++;
        }

        return dp[k-1];
    }
};  