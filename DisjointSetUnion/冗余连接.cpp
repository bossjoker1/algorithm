class Solution {
public:

    int rank[1001];
    
    // 边查，边压缩路径
    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    // 朝高的合并
    void Union(vector<int>& parent, int index1, int index2) {
        int x = Find(parent, index1), y = Find(parent, index2);
        if(x==y) return;
        if(rank[x] < rank[y]){
            parent[x] = y;
        }else{
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++; 
        }

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodesCount = edges.size();
        vector<int> parent(nodesCount + 1);
        // 初始化
        for (int i = 1; i <= nodesCount; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
        for (auto& edge: edges) {
            int node1 = edge[0], node2 = edge[1];
            if (Find(parent, node1) != Find(parent, node2)) {
                Union(parent, node1, node2);
            } else {
                return edge;
            }
        }
        return {};
    }
};

