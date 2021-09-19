// 困难题 挑战
// woc我第一遍读起来竟然觉得没什么太大的不同？太菜了。。
// 分三种情况，，好好理解下
class Solution {
public:

    int find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = find(parent, parent[index]);
        }
        return parent[index];
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        bool flag = false;
        // 父节点 并查集
        vector<int> father(n), parent(n);
        // 记录边，结果
        vector<int> edge1, edge2, res;
        cout<<edge1.size()<<endl;
        for(auto & edge : edges){
            int p = edge[0];
            int c = edge[1];

            // 初始化并查集
            if(parent[p] == 0) parent[p] = p;
            if(parent[c] == 0) parent[c] = c;

            if(father[c]!=0){
                // 有一个根节点了
                edge1 = {father[c], c};
                edge2 = edge;
                flag = true;
            }else{
                father[c] = p;
                if(find(parent, p) != find(parent, c)){
                    parent[find(parent, c)] = find(parent, p); //合并
                }else{
                    // 存在环了
                    res = edge;
                }
            }
        }
        if(flag !=0 && edge2.size() != 0) return res.size() == 0?edge2:edge1;
        else return res;
    }
};