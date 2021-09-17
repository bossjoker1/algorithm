//prim算法：用于求多个点之间的最短路径
//核心思想是将点分为两个集合，任意选择一个点进入其中一个集合
//在另一个集合中选择到该集合所有点（一开始就一个）的最短边
//然后将边对应的点加入到第一个集合中
//重复，直至第一个集合为全集
int prim(vector<vector<int>>& points, int start){
    int n = points.size();
    int res = 0;

    //将points转化为邻接矩阵，更方便
    vector<vector<int >> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for(int j = i+1;j<n;j++){
            int dist = abs(points[i][0]- points[j][0]) + abs(points[i][1]-points[j][1]);
            g[i][j] = dist;
            g[j][i] = dist;
        }
    }
    //记录V[i]到第一个集合的最近距离
    vector<int> lowcost(n, INT_MAX);
    //记录是否加入到了第一个集合，初始化为-1
    vector<int> v(n, -1);

    //将start加入到第一个集合中，并更新状态
    v[start] = 0; 
    for(int i = 0; i< n; i++){
        if(i == start) continue;
        lowcost[i] = g[i][start];
    }

    //还有剩余n-1个节点
    for(int i = 1;i < n;i++){
        int index = -1;
        int minval = INT_MAX;
        for(int j = 0 ;j < n;j++){
            if(v[j] == 0)continue;
            if(lowcost[j] < minval){
                index = j;
                minval = lowcost[j];
            }
        }
        res += minval;
        v[index] = 0;
        lowcost[index] = -1;

        for(int j = 0; j < n;j ++){
            if(v[j] == -1 && g[j][index] < lowcost[j])
                lowcost[j] = g[j][index];
        }
        
    }
    return res;
}

int minCostConnectPoints(vector<vector<int>> & points){
    return prim(points, 0);
}