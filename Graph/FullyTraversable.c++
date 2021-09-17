// .1579 Remove Max Number of Edges to Keep Graph Fully Traversable
// 用到了并查集的知识
// 主要是find, merge, 以及路径压缩和按秩合并

class Solution {
public:
    vector<int> par;
    int cnt; //连通分量的个数
    int getRoot(int x){
        int root = x;
        while(par[root]!=root){
            root = par[root];
        }
        while(par[x]!=root){
            int tmp = par[x];
            par[x] = root;   // 将x 的父节点直接指向根节点即压缩路径
            x = tmp;
        }
        return root;
    }
    void merge(int x,int y){
        int _x = getRoot(x);
        int _y = getRoot(y);
        if(_x!=_y){
            par[_x]=_y;
            cnt--;
        }
    }
    //初始化
    void init(int n){
        //cnt为集合个数，初始化每个结点视为一个集合
        cnt = n;
        for(int i =1;i<=n;i++){
            par[i] = i;
        }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        par = vector<int>(n+1,0);
        int ans = 0;
        //分别存储第一种到第三种类型的边
        int cnt1 = 0,cnt2 = 0,cnt3 = 0;
        init(n);
        //判断对于Alice是否连通
        for(int i = 0;i<edges.size();i++){
            if(edges[i][0]==1||edges[i][0]==3){
                merge(edges[i][1],edges[i][2]);
                cnt1++;
            }
        }
        if(cnt!=1)
            return -1;
        init(n);
        //判断对于Bob是否连通
        for(int i = 0;i<edges.size();i++){
            if(edges[i][0]==2||edges[i][0]==3){
                merge(edges[i][1],edges[i][2]);
                cnt2++;
            }
        }
        if(cnt!=1)
            return -1;
        init(n);
        //添加第三种类型的边
        for(int i = 0;i<edges.size();i++){
            if(edges[i][0]==3){
                merge(edges[i][1],edges[i][2]);
                cnt3++;
            }
        }
        //去除第三种类型的边
        cnt1-=cnt3;
        cnt2-=cnt3;
        //多余的第三种类型的边
        ans+=(cnt3-(n-cnt));
        //多余的其余两种类型的边
        ans += cnt1-(cnt-1)+cnt2-(cnt-1);
        
        return ans;
    }
};
