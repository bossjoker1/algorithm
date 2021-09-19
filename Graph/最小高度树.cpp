// 开始准备DFS暴力解
// 其实就是剪枝问题
// 找度为1的点一圈圈减下去

class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<int> res;
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        // init the graph
        for(int i = 0; i < n-1;  i++){
            // 无向图
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }

        queue<int> q;
        for(int i = 0 ; i < n; i++){
            // 度为1的入列
            if(degree[i] == 1)  q.push(i);
        }

        while(!q.empty()){
            res.clear();
            int len = q.size();
            while(len--){
                int temp = q.front();
                q.pop();
                // 这里其实是一个暂存，我们真正要的是最后加入的叶子节点，
                // 这时候的叶子节点就是最终能有最小高度的根节点
                res.push_back(temp);
                for(auto &i : graph[temp]){
                    degree[i] -- ;
                    if(degree[i] == 1) q.push(i);     
                }
            }
        }

        return res;
    }
};