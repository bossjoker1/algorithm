// 区间修改 加上x
// 区间和查询
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
#define lchild i << 1
#define rchild i << 1 | 1
#define mid ((l + r) >> 1)
int w[N];
struct tree 
{
	ll l;
	ll r;
	ll sum; // 原来的和
	ll add; // 增量的累加值
}node[N << 2];
inline void update(int i)
{
	node[i].sum = node[lchild].sum + node[rchild].sum;
}
inline void build(int i, ll l, ll r)
{
	node[i].l = l;
	node[i].r = r;
	if(l == r)
	{
		node[i].sum = w[l];
		node[i].add = 0;
		return;
	}
	build(lchild, l, mid);
	build(rchild, mid + 1, r);
	update(i);
}
inline void pushdown(int i)
{
	ll l = node[i].l;
	ll r = node[i].r;
	ll len = r - l + 1;
	node[lchild].sum += node[i].add * (len - (len >> 1));
	node[rchild].sum += node[i].add * (len >> 1);
	node[lchild].add += node[i].add;
	node[rchild].add += node[i].add;
	node[i].add = 0; // 已更新完，增量置为0
}
inline void modify(int i, ll x, ll y, ll t)
{
	ll l = node[i].l;
	ll r = node[i].r;
	if(x <= l && r <= y)
	{
		node[i].sum += (r - l + 1) * t;
		node[i].add += t;
		return;
	}
	pushdown(i); // 向下推送增量值
	if(x <= mid)
		modify(lchild, x, y, t);
	if(mid < y)
		modify(rchild, x, y, t);
	update(i);
}
inline ll getsum(int i, ll x, ll y)
{
	ll l = node[i].l;
	ll r = node[i].r;
	if (x <= l && r <= y)
		return node[i].sum;
	pushdown(i);
	ll ans = 0;
	if(x <= mid)
		ans += getsum(lchild, x, y);
	if(mid < y)
		ans += getsum(rchild, x, y);
	return ans;
}
int main()
{
	ll n, m;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &w[i]);
	build(1, 1, n);
	for (int i = 1; i <= m; i ++)
	{
		ll x, y, k;
		int c;
		scanf("%d", &c);
		if(c == 1)
		{
			scanf("%lld%lld%lld", &x, &y, &k);
			modify(1, x, y, k);
		}
		else
		{
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", getsum(1, x, y));
		}
	}
	return 0;
}