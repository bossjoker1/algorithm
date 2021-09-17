//动态规划，时间复杂度O(n^2)，数据太大的话，过不了哦
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        for(int i = 3;i <= n; i++){
            for(int j = 2;j < i;j++)
                dp[i] = max(dp[i], max((i-j)*j, j*dp[i-j]));
        }
        return dp[n];
    }
};

//数学知识理解，分三段才尽可能得大，贪心思想
class Solution {
public:
    int cuttingRope(int n) {
        if(n<4)
            return n-1;
        int res = 1;
        while (n > 4){
            res*=3;
            n-=3;
        }
        return res*n;
    }
};