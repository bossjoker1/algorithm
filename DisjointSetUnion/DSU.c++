//并查集方法实现，平均时间复杂度为O(a(n)), a(n)为阿克曼函数的反函数，比O(logn)要快
//主要为 查找 + 合并
//par[i] = i 则i为所在树的根
int par[MAX_N]; //父亲
int rank[MAX_N]; //树的高度

//初始化
void init(int n){
    for(int i = 0 ;i < n; i++){
        par[i] = i;
        rank[i] = 0;
    }
}

//查询树根
int find(int x){
    if (par[x] == x)
        return x;
    else
        //递归查找，同时压缩路径
        return par[x] = find(par[x]);
}

//合并 x 和 y 所属的集合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) return;

    if(rank[x] < rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++; 
    }
}  

bool same(int x, int y){
    return find(x) == find(y);
}

