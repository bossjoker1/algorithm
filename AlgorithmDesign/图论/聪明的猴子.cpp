#include <cstdio>
#include <cmath>
#include <queue>
 
using namespace std;
 
const int maxn = 5005;
const double inf = 1e16;

typedef long long ll;

int x[maxn], y[maxn], a[maxn],vis[maxn];
ll dist[1100000];

inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

inline ll dis(int i, int j) {
    return (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
}

struct node {
    int id;
    ll dist;
    node(int i, ll d) : id(i), dist(d) {}
    bool operator < (const node& rhs) const {
        return dist > rhs.dist;
    }
};
 
 priority_queue<node> q;
 
int main() {
    int n, m;
    n = read();
    for(int i = 1; i <=n; i++ ) a[i] = read();
    m = read();
    for (int i = 1; i <= m; ++i) x[i] = read(), y[i] = read();
    double ans = 0;
    for (int i = 2; i <= n; ++i) dist[i] = inf;
    ll max_d = -1;
    q.push(node(1, 0));
    while (!q.empty()) {
        int u = q.top().id;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans += dist[u];
        max_d = max(max_d, dist[u]);      
        for (int v = 1; v <= n; ++v) {
            if (v == u) continue;
            if (dist[v] > dis(u, v)) {
                dist[v] = dis(u, v);
                q.push(node(v, dist[v]));
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(a[i]*a[i] >= max_d) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
