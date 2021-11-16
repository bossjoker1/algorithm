// 一个方法是使用计算最小生成树的个数，但是这个方法只能用于数据量少且好的情况
// 这里用到的性质是最小生成树与次优生成树的区别只有一个边
#include<bits/stdc++.h>
using namespace std;

#define MAX 0x3f3f3f3f

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

const int N=105;

int mp[N][N], vis[N], dis[N], st[N], max1[N][N], pre[N];

int n, m, ans;

inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

inline void init(){
    rep(i, 0, N-1){
        rep(j, 0, N-1){
            mp[i][j] = mp[j][i] = MAX;
            max1[i][j] = max1[i][j] = 0;
        }
    }
}

void prim(){
    int minV, top = 0, k;
    vis[1] = 0; ans = 0;
    rep(i, 1, n){
        pre[i] = 1;
        dis[i] = mp[1][i];
    }
    dis[1] = 0;

    st[top++] = 1; // 保存在MST上的节点
    rep(i,1,n){
        minV = MAX;
        rep(j, 1, n){
            if(!vis[j] && minV > dis[j])
                minV = dis[j];
                k = j;
        }

        if(minV == MAX)
            break; //不连通

        vis[k] = 1;

        ans += minV;
        // 维护MST上的节点和新加入点的最大距离
        rep(j, 0, top-1)
            max1[st[j]][k] = max1[k][st[j]] = max(minV, max1[st[j]][pre[k]]);
        st[top++] = k; // 保存MST的结点

        rep(j, 1, n){
            if(!vis[j]&&dis[j]>mp[k][j]){
                dis[j] = mp[k][j];
                pre[j] = k;
            }
        }
    }
}

int main(){
    int t = read();
    while(t--){
        init();
        int u, v, value;
        n = read(), m = read();
        rep(i, 0, m-1){
            u = read(), v = read(), value = read();
            mp[u][v] = mp[v][u] = value;
        }

        prim();

        int minn = MAX;

        rep(i, 1, n){
            rep(j, 1, n){
                if(i!=j&&i!=pre[j]&&j!=pre[i])
                    minn = min(minn, mp[i][j] - max1[i][j]);
            }
        }

        if(minn) printf("$d\n", ans);
        else printf("Not Unique!\n");
    }

    return 0;
}