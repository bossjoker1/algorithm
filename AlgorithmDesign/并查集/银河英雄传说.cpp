#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
 
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAX_N 30005

typedef long long ll;

// sum[i]表示包括自己前面有多少人
// cnt[i]表示以i为祖先的集合有多少人
int par[MAX_N], sum[MAX_N], cnt[MAX_N];
 
inline int max(int x,int y){return x>y?x:y;}
 
inline int read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

//初始化
inline void init(int n){
    for(int i = 1 ;i <= n; i++){
        par[i] = i;
        sum[i] = 1;
        cnt[i] = 1;
    }
}

//查询树根
int find(int x){
    if (par[x] == x)
        return x;
    int p = par[x];
    par[x] = find(par[x]);
    sum[x] += sum[p] - 1;  // -1是因为p算了两次
    return par[x];
}

//合并 x 和 y 所属的集合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    sum[x] = cnt[y] + 1; //更新祖先x排名, 需要find才能作用到集合内的元素
    cnt[y] += cnt[x]; // 更新被合并祖先y的集合大小
    par[x] = y;
}  

void query(int x, int y){
    if(find(x) != find(y)){
        printf("-1\n");
    }else{
        printf("%d\n", abs(sum[x] - sum[y])-1);
    }
}


int main(){
    init(MAX_N);
    int T = read();
    char c;int i, j;
    rep(k, 1, T){
        cin>>c;
        i = read(),j = read();
        if(c == 'M'){
            unite(i, j);
        }else{
            query(i, j);
        }
    }
           
    return 0;
}