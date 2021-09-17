//743
//SPFA算法，特点是可以判断存在负权的图
//用一个队列维护需要松弛的点
//队列为空则退出，同一个点可以反复进队
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //初始化邻接矩阵
        vector<vector<long long>> graph(n+1,vector<long long>(n+1,INT_MAX));
        //主对角线初始化为00
        for(int i = 1;i <=n;i++) graph[i][i] = 0;
        for(auto e: times) graph[e[0]][e[1]] = e[2];

        vector<int> dist(n+1, INT_MAX);

        queue<int> q;
        q.push(k);
        dist[k] = 0;//起始点距离为0

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int t = 1;t<=n;t++){
                if(dist[front] + graph[front][t] < dist[t]){
                    //松弛
                    dist[t] = dist[front] + graph[front][t];
                    q.push(t);
                }
            }
        }

        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};  