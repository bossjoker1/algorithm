// 看不懂
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510;
int n, m, k, x, y, z, cnt, p[MAXN], head[MAXN], vis[MAXN], dp[MAXN][4200];
struct edge
{
	int v, w, next;
}e[MAXN << 1];

priority_queue < pair<int, int> > q;

inline int read()
{
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}
inline void write(int x)
{
	char F[200];
	int tmp = x > 0 ? x : -x;
	if (x < 0)putchar('-');
	int cnt = 0;
	while (tmp > 0)
	{
		F[cnt++] = tmp % 10 + '0';
		tmp /= 10;
	}
	while (cnt > 0)putchar(F[--cnt]);
}

void add_edge(int u, int v, int w) { //链式前向星加边
	e[++cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}
void dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) {
		pair <int, int> a = q.top();
		q.pop();
		if (vis[a.second]) { continue; }
		vis[a.second] = 1;
		for (int i = head[a.second]; i; i = e[i].next) {
			if (dp[e[i].v][s] > dp[a.second][s] + e[i].w) {
				dp[e[i].v][s] = dp[a.second][s] + e[i].w;
				q.push(make_pair(-dp[e[i].v][s], e[i].v));
			}
		}
	}
	return;
}
int main() {
	memset(dp, 0x3f, sizeof(dp));
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		x = read(), y = read(), z = read();
		add_edge(x, y, z), add_edge(y, x, z); //无向图
	}
	for (int i = 1; i <= k; i++) {
		p[i] = read();
		dp[p[i]][1 << (i - 1)] = 0;
	}
	for (int s = 1; s < (1 << k); s++) {
		for (int i = 1; i <= n; i++) {
			for (int subs = s & (s - 1); subs; subs = s & (subs - 1)) {
				dp[i][s] = min(dp[i][s], dp[i][subs] + dp[i][s ^ subs]);
			}
			if (dp[i][s] != 0x3f3f3f3f) { q.push(make_pair(-dp[i][s], i)); }
		}
		dijkstra(s);
	}
	write(dp[p[1]][(1 << k) - 1]);
	return 0;
}