//.49
//关键：将字符串进行排序作为map的key，相同的加入即可（auto真好用
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(auto &str: strs){
            auto key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }

        for(auto &m : mp){
            res.push_back(m.second);
        }
        return res;
    }
};