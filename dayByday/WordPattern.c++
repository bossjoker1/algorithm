// .290 easy
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //双向映射
        unordered_map<char ,string> mp;
        unordered_map<string, char> rmp;
        stringstream ss(str); 
        string s;
        for(char c: pattern){
            if(!(ss>>s) || (mp.count(c) == 1 && mp[c] != s)
            ||(rmp.count(s) == 1 && rmp[s] != c))
                return false;
            mp[c] = s; rmp[s] = c;
        }
        //如果为真说明str长度大于pattern匹配长度了
        return (ss >> s) ? false :true;
    }
};