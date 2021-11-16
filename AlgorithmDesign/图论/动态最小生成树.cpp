// 纯暴力能过
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
#define maxint 0x3f3f3f3f
typedef long long ll;

const int maxn = 255;
const int maxe = 40005;

inline int max(int x, int y) { return x > y ? x : y; }

inline int read() {
    ll x = 0, f = 1; char ch = ' ';
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar(); }
    return f == 1 ? x : -x;
}

int n, m, k;
int vis[maxn], dis[maxn], edges[maxn][maxn];

void prim() {
    memset(vis, 0, sizeof(vis));
    memset(dis, maxint, sizeof(dis));
    vis[1] = 1;
    int num = 1, sum = 0;
    rep(i, 1, n) dis[i] = edges[1][i];

    rep(i, 1, n) {
        int minv = maxint, k;

        rep(j, 1, n) {
            if (!vis[j] && minv > dis[j]) {
                minv = dis[j];
                k = j;
            }
        }

        if (minv == maxint) break;

        num++;
        sum += minv;
        vis[k] = 1;

        rep(j, 1, n) {
            if (!vis[j] && dis[j] > edges[k][j]) dis[j] = edges[k][j];
        }
    }
    if (num < n) {
        printf("-1 ");
    }
    else {
        printf("%d ", sum);
    }
}

void dijkstra() {
    memset(vis, 0, sizeof(vis));
    memset(dis, maxint, sizeof(dis));
    int sum = 0;
    rep(i, 1, n) {
        dis[i] = edges[1][i];
    }

    vis[1] = 1;

    rep(i, 1, n-1) {
        int minv = maxint, k;

        rep(j, 1, n) {
            if (!vis[j] && minv > dis[j]) {
                minv = dis[j];
                k = j;
            }
        }

        if (minv == maxint) {
            printf("-1\n");
            return;
        }

        vis[k] = 1;

        rep(j, 1, n) {
            int temp = (edges[k][j] == maxint ? maxint : (minv + edges[k][j]));
            if (!vis[j] && dis[j] > temp)
                dis[j] = temp;
        }
    }

    rep(i, 2, n) {
        sum += dis[i];
    }

    printf("%d\n", sum);

}



int main() {
    memset(edges, maxint, sizeof(edges));
    n = read(), m = read(), k = read();
    int x, y, z, c;
    rep(i, 1, m) {
        x = read(), y = read(), z = read();
        edges[x][y] = edges[y][x] = z;
    }

    rep(i, 1, k) {
        c = read();
        if (c == 1) {
            x = read(), y = read();
            edges[x][y] = edges[y][x] = maxint;
        }
        else {
            x = read(), y = read(), z = read();
            edges[x][y] = edges[y][x] = z;
        }
        prim(); 
        dijkstra();
    }
    return 0;
}