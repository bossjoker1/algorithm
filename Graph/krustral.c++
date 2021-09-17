//最小生成树问题
//prim算法与dijkstra算法类似，只是需要维护两个集合
//krustral算法是直接按照权值大小进行选择，如果形成环则丢弃
//判断是否会成环，如果u, v是同一连通分量，则再添加一边e，则必成环
//这种是否为同一类的问题，自然想到通过并查集来维护
struct edge { int u, v, cost;};

bool comp(const edge&e1, const edge&e2){
    return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

int krustral(){
    sort(es, es+E, comp);
    //并查集初始化
    init_union_find(V);
    int res = 0;
    for(int i = 0; i < E; i++){
        edge s = es[i];
        if(!same(e.u, e.v)){
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}