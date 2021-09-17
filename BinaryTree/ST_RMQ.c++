//基于线段树的区间最小值查询结构
//1.求出给定区间的最小值
//2.修改某个值后对结构进行维护
//一般是完美二叉树
const int N;
const int MAX_N = 1<<N;
//存储线段树的全局数组
int n, dat[2*MAX_N-1];
//初始化
void init(int n_){
    n = 1;
    while(n < n_) n *= 2;
    //把所有值设为INT_MAX
    for(int i = 0;i < n-1;i++) dat[i] = INT_MAX;
}

//更新第k个值为a
void update(int k, int a){
    k += n-1;//移动到根节点
    dat[k] = a;
    //向上更新
    while(k>0){
        k = (k-1)/2;
        dat[k] = min(dat[k*2+1], dat[k*2+2]);
    }
}

//求[a, b)最小值，k为节点编号，l, r表示[l, r)
//外部调用时为query(a, b, 0, 0, n)
int query(int a, int b, int k, int l, int r){
    //[l, r)与[a, b)不相交直接返回INT_MAX
    if(a>=r||b<=l) return INT_MAX;
    //[a, b)完全包含了[l, r)，则直接返回当前区间最小值
    if(a<=l&&r<=b) return dat[k];
    else{
        int vl = query(a, b, k*2+1, l, (1+r)/2);
        int vr = query(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    }
}