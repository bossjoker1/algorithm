// 听名字似乎是个很经典的题
// 原来是找出多余的边让其恢复成树，数据结构书上好像有，忘了..
// 用并查集应该挺好做的，就是也不太熟
// 集合就是连通分量，如果下一条边的两个节点属于同一个连通分量，则必然形成环

class Solution {
public:
    // 注意都是引用操作，边查找边缩边加到祖先下
    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodesCount = edges.size();
        vector<int> parent(nodesCount + 1);
        // 初始化，最大可能的祖先数
        for (int i = 1; i <= nodesCount; ++i) {
            parent[i] = i;
            
        }
        for (auto& edge: edges) {
            int node1 = edge[0], node2 = edge[1];
            // 查找祖先
            if (Find(parent, node1) != Find(parent, node2)) {
                // 合并
                Union(parent, node1, node2);
            } else {
                return edge;
            }
        }
        return {};
    }
};



