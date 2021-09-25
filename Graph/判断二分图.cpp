// 二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，
// 并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图

// 初步分析，似乎符合并查集的特征

// 评论区大神，双色标记法 0 1 
class Solution {
private:
    bool dfs(const vector<vector<int>> &g, int i, int c, vector<int> &v) {      //返回第i个点染c色能否成功
        if (v[i] != -1) return v[i] == c;                                       //第i个点已染过
        v[i] = c;                                                               //对第i个点染上c色
        for (int j : g[i]) if (!dfs(g, j, !c, v)) return false;                 //递归相邻的点，c => !c 换色
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> v(n, -1);                                                   //-1表示待染色
        for (int i = 0; i < n; i++) if (v[i] == -1 && !dfs(graph, i, 0, v)) return false;
        return true;
    }
};


// 失败，有些细节没考虑到 53/80
class Solution {
public:

    // 边查，边压缩路径
    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        int x = Find(parent, index1), y = Find(parent, index2);
        if(x==y) return;
        parent[x] = y;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> parent(n);

        // 初始化
        for(int i = 0; i < n; i++)
            parent[i] = i;

        for(int k = 0 ; k < n; k ++){
            for(int i = 0; i < n; i++){
                if(!count(graph[k].begin(), graph[k].end(), i) && i != k){
                    if(Find(parent, k) != Find(parent, i)){
                        Union(parent, k, i);
                    }
                }
            }
        }

        set<int> res;

        for(int i = 0; i < n; i++){
            int p = Find(parent, i);
            res.insert();
        }

        return res.size() == 2;
        
    }
};



