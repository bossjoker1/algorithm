// 边界条件对着错误才想到麻了
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户

class Solution {
public:
    int numDecodings(string s) {
        // dp[i]表示前i位的种数
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n ; i++){
            if(i == 1){
                if(s[i-1] == '0') return 0;
                else dp[i] = 1;
                continue;
            }
            if(s[i-2] != 48 && s[i-1] != 48 && ((s[i-2]-48)*10 + (s[i-1] - 48)) <= 26 ){
                dp[i] = dp[i-1] + dp[i-2];
            }else if(s[i-1] == 48){
                if( s[i-2] != 49 && s[i-2] != 50)
                    return 0;
                dp[i] = dp[i-2];
            } 
            else{
                dp[i] = dp[i-1];
            }
        }

        return dp[n];      
    }
};

// 压缩内存

class Solution {
public:
    int numDecodings(string s) {
        // dp[i]表示前i位的种数
        int n = s.size();
        int a, b, c;
        a = 1;
        for(int i = 1; i <= n ; i++){
            if(i == 1){
                if(s[i-1] == '0') return 0;
                else b = 1;
                continue;
            }
            if(s[i-2] != 48 && s[i-1] != 48 && ((s[i-2]-48)*10 + (s[i-1] - 48)) <= 26 ){
                c = b + a;
            }else if(s[i-1] == 48){
                if( s[i-2] != 49 && s[i-2] != 50)
                    return 0;
                c = a;
            } 
            else{
                c = b;
            }

            a = b;
            b = c;
        }

        return b;      
    }
};
