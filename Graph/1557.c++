//开始还在想是dfs还是bfs
//没想到就是求入度为0的点，用一个set维护入度不为0的点
//再用全集相减即得
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        unordered_set<int> back;
        for(auto edge:edges){
            back.insert(edge[1]);
        }
        for(int i = 0 ;i < n;i ++){
            if(!back.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};