//.797 
//套用回溯框架
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        backtrack(graph, 0, n - 1, {0}, res);
        return res;    
    }

private:
    void backtrack(vector<vector<int>>& graph, int src, int dst,
                   vector<int> cur, vector<vector<int>>& res) {
        // 回溯出口
        if (src == dst) {
            res.push_back(cur);
            return;
        }

        for (const auto& neighbor : graph[src]) {
            // 做选择
            cur.push_back(neighbor);
            // 递归回溯
            backtrack(graph, neighbor, dst, cur, res);
            // 撤销选择
            cur.pop_back();
        }
    }    
};