//插入和找最小值用堆来维护
//复杂度为: O(|E|log|V|)
struct edge{int to, cost;};

typedef pair<int int>  P; //first为最短距离，second为顶点编号

int V;
vector<edge> G[MAX_V];
int dist[MAX_V];

void dijkstra(int s){
    // 贪心思想提高效率，直接vector也行但要慢很多
    priority_queue<P, vector<P>, greater<P>> que;
    fill(dist, d+v, INT_MAX);
    dist[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(dist[v] <p.first) continue; //取出来的不是最小值，丢弃
        for(int i = 0; i < G[v].size(); i++){
            //遍历相邻边
            edge e = G[v][i];
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}