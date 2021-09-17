//139
//对于s[:i]，通过j遍历并检查dp[j]&&s[j, i-j]是否有子串
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> WordDictSet;
        for(auto t: wordDict){
            WordDictSet.insert(t);
        }
        int n = s.size();
        vector<bool> dp(n+1);
        dp[0] = true;
        for(int i = 1; i <=n;i++ ){
            for(int j = 0; j <i;j++){
                if(dp[j]&&WordDictSet.find(s.substr(j, i-j))!=WordDictSet.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];  
    }
};  