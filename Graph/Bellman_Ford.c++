//单源最短路
// Bellman-Ford算法
// 可以判断负边，但是时间复杂度不如dijkstra，可以看到循环那里重复了许多操作
struct edge {int from, to, cost;};

edge es[MAX_E];
int d[MAX_V];
int V, E;

void shortest_path(int s){
    for(int i = 0; i < V; i++) d[i] = INT_MAX;
    d[s] = 0; //s为起始点
    while (true)
    {
        bool update = false;
        for(int i = 0 ;i < E; i++){
            edge e = es[i];
            if(d[e.from] != INT_MAX && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
            }
        }
        if(!update)  break;
    }
}