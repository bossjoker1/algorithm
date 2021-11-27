// spfa 可能会被卡
#include<bits/stdc++.h>
#define maxn 1010
#define maxm 1010101
#define Inf 2147483647
using namespace std;
 
struct Edge{
	int u, v, cap, flow, cost;
	int next;
}e[maxm];
 
int n, m, s, t;
int flow = 0, cost = 0;
int fi[maxn], ecnt;
int inq[maxn], p[maxn];	//p：上一条边 
int d[maxn];	//spfa 
int a[maxn];	//可改进量 
 
void add_edge(int u, int v, int cap, int cost) {
	ecnt++;
	e[ecnt] = (Edge){u, v, cap, 0, cost, fi[u]};
	fi[u] = ecnt;
}
 
bool spfa(int s, int t) {
	for(int i = 1; i <= n; i++)
		d[i] = Inf;
	memset(inq, 0, sizeof(inq));
	d[s] = 0, inq[s] = 1, p[s] = 0, a[s] = Inf;
	int q[maxn], head = 0, tail = 1;
	q[head] = s;
	while(head < tail) {
		int u = q[head++];
		inq[u] = 0;
		for(int i = fi[u]; i != -1; i = e[i].next)
			if(e[i].cap > e[i].flow && d[e[i].v] > d[u] + e[i].cost) {
				d[e[i].v] = d[u] + e[i].cost;
				p[e[i].v] = i;
				a[e[i].v] = min(a[u], e[i].cap - e[i].flow);
				if(!inq[e[i].v]) {
					q[tail++] = e[i].v, inq[e[i].v] = 1;
				}
			}
	}
	if(d[t] == Inf) return false;
	flow += a[t], cost += d[t]*a[t];
	int u = t;
	while(u != s) {
		e[p[u]].flow += a[t];
		e[p[u]^1].flow -= a[t];
		u = e[p[u]].u;
	}
	return true;
}
	
int main() {
	memset(fi, -1, sizeof(fi));
	scanf("%d%d", &n, &m);
	s = 1, t = n;
	for(int i = 1; i <= m; i++) {
		int u, v, cap, cost;
		scanf("%d%d%d%d", &u, &v, &cap, &cost);
		add_edge(u, v, cap, cost);
		add_edge(v, u, 0, -cost);
	}
	while(spfa(s, t));
	printf("%d", cost);
	return 0;
}