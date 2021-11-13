// 两个重要性质
// 1）同一种权值的边的个数相等
// 2）用Kruscal按照从小到大，处理完某一种权值的所
// 有边后，图的连通性相等
// 所以我们先对边进行排序，并维护一个数据结构，其中为相同的边的个数和左右边界
// dfs进行回溯，同时注意不能用路径压缩的find

#include<bits/stdc++.h>
using namespace std;

#define mod 31011

const int MAXN=105;
const int MAXE=1005;

inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}


struct Edge{
    int x, y, dis;
    bool operator < (const Edge &a) const{
        return dis < a.dis;
    }
}edge[MAXE];

struct build{
    int l, r, cnt;
}a[MAXE];

int tot, n, m, par[MAXN], sum;

// 不压缩路径
int find(int x){
    if(par[x] != x)
        return find(par[x]);
    return x;
}

int kruskal(){
    sort(edge+1, edge+m+1);

    for(int i = 1; i<=n; i++) par[i] = i;

    int cnt = 0;

    for(int i = 1; i<=m; i++){
        if(edge[i].dis != edge[i-1].dis){
            tot++;
            a[tot].l = i;
            a[tot-1].r = i-1;
        }

        int x = find(edge[i].x);
        int y = find(edge[i].y);
        if(x!=y){
            par[y] = x;
            a[tot].cnt++;
            cnt++; 
        }
    }
    a[tot].r = m;
    return cnt;
}

void dfs(int x, int now, int num){
    if(now == a[x].r + 1){
        if(num == a[x].cnt) sum++;
        return;
    }

    int fx = find(edge[now].x);
    int fy = find(edge[now].y);

    if(fx != fy){
        par[fx] = fy;

        dfs(x, now+1, num+1);

        par[fx]=fx, par[fy] = fy;

    }
    dfs(x, now+1, num);
}

int main(){
    n = read(), m = read();

    int x, y, z;

    for(int i = 1; i<=m; i++){
        edge[i].x = read(), edge[i].y = read(), edge[i].dis = read();
    }

    int num = kruskal();

    if(num != n-1){
        printf("0\n");
        return 0;
    }

    for(int i = 1; i<=n; i++){
        par[i] = i;
    }

    int res = 1;

    for(int i = 1; i<=tot; i++){
        sum = 0;
        dfs(i, a[i].l, 0);

        res = res * sum % mod;

        for(int j = a[i].l; j<=a[i].r;j++){
            int x = find(edge[j].x);
            int y = find(edge[j].y);
            if(x!=y) par[y] = x;
        }
    }
    printf("%d\n", res);

    return 0;
}





