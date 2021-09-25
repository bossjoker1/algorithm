// 求最长公共子序列的变体，最后用两个字符串的长度和减去最长公共子序列长度即得到结果
// dp[i][j] 表示 word1[0 - i] 与 word2[0 - j]的最长公共子序列长度

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for(int i = 1 ; i <= n; i++){
            for(int j = 1; j <= m ; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return m + n - 2*dp[n][m];
    }
};