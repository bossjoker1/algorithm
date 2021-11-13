#include <cstdio>
#include <cmath>
#include <queue>
 
using namespace std;
 
const int maxn = 1005;
const double inf = 1e16;

int x[maxn], y[maxn], a[maxn],vis[maxn];
double dist[maxn];

typedef long long ll;

inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

inline long long pw2(int x) {
    return 1LL * x * x;
}
 
inline double dis(int i, int j) {
    return sqrt(pw2(x[i] - x[j]) + pw2(y[i] - y[j])); }

struct node {
    int id;
    double dist;
    node(int i, double d) : id(i), dist(d) {}
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
    double max_d = -1;
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
    printf("%.2f", ans);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(a[i]*1.0 >=  max_d) sum++;
    }
    // printf("%d\n", sum);
    return 0;
}
