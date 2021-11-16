#include<stdio.h>
#include<algorithm>
using namespace std;


#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)

#define MAXN 5005

typedef long long ll;

inline ll max(ll x, ll y) { return x > y ? x : y; }

inline ll read() {
    ll x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

int n, m, k, cnt, cnt2;

struct edge { ll u, v, cost; };

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

edge es[MAXN], es2[MAXN];
int par[105];
int h[105];
int costs[105];

//初始化
inline void init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        h[i] = 0;
    }
}

//查询树根
int find(int x) {
    if (par[x] == x)
        return x;
    else
        //递归查找，同时压缩路径
        return par[x] = find(par[x]);
}

//合并 x 和 y 所属的集合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (h[x] < h[y]) {
        par[x] = y;
    }
    else {
        par[y] = x;
        if (h[x] == h[y]) h[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}


ll krustral() {
    //并查集初始化
    ll res = 0, count = 0, num = 0;
    for (int i = 1; i <= cnt; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
            num++;
            count++;
        }
    }
    for (int i = 1; i <= cnt2; i++) {
        if (num == n - 1) break;
        edge e = es2[i];
        if (!same(e.u, e.v)) {
            if (e.u == 1 || e.v == 1) {
                count++;
                if (count > k) continue;
            }
            unite(e.u, e.v);
            res += e.cost;
            num++;
        }
    }
    return res;
}


int main() {
    n = read(), m = read(), k = read();
    init(n);
    int cost;
    costs[1] = 1;
    rep(i, 1, m) {
        ll u, v, cost;
        u = read(), v = read(), cost = read();
        es2[++cnt2].u = u, es2[cnt2].v = v, es2[cnt2].cost = cost;
        if (u != 1 && v != 1) 
            costs[u] = costs[v] = 1;
    }
    rep(i, 1, m) {
        edge e = es2[i];
        if (!(costs[e.v]&&costs[e.u]))
            es[++cnt] = es2[i];
    }
    sort(es + 1, es + cnt + 1, comp);
    sort(es2 + 1, es2 + cnt2 + 1, comp);

    printf("%lld\n", krustral());

    return 0;
}