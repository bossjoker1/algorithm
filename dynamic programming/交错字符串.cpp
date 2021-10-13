// 字符串的dp问题
// 感觉对这一类问题经常想不到什么好方法，没有整数或者二维dp来的直观
// 看别人评论，字符串子串匹配都可以用dp解决
// dp[i][j]表示s1[0~i-1]和s2[0~j-1]能否交错组成s3[0~i+j-1]

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1));
        
        // basecase
        dp[0][0] = true;
        for(int i=1;i<=n1;++i)
        {
            dp[i][0] = dp[i-1][0]&&(s1[i-1]==s3[i-1]);
        }
        for(int i=1;i<=n2;++i)
        {
            dp[0][i] = dp[0][i-1]&&(s2[i-1]==s3[i-1]);
        }


        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                dp[i][j] = dp[i-1][j]&&s1[i-1]==s3[i-1+j]||dp[i][j-1]&&s2[j-1]==s3[i-1+j];
            }
        }
        return dp[n1][n2];
    }
};