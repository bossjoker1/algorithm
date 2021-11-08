#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
#define MOD 571373
#define lchild i << 1
#define rchild i << 1 | 1
#define mid ((l + r) >> 1)
int w[N];
struct tree 
{
	ll l;
	ll r;
	ll sum;
	ll xor;
	ll mul; 
}node[N << 2];
inline void update(int i) //修改子节点后，当前节点的值重新计算，前提是子节点已经计算了sum 
{
	node[i].sum = (node[lchild].sum + node[rchild].sum)%MOD;
}
inline void build(int i, ll l, ll r)
{
	node[i].l = l;
	node[i].r = r;
	node[i].xor = 0;
	node[i].mul = 1;
	if(l == r)
	{
		node[i].sum = w[l]%MOD;
		return;
	}
	build(lchild, l, mid);
	build(rchild, mid + 1, r);
	update(i);
}
inline void pushdown(int i)//计算当前标记对子节点的影响，同时将当前节点标记清零，当前节点的sum通过相应的update更新 
{
	ll l = node[i].l;
	ll r = node[i].r;
	ll len = r - l + 1;
	node[lchild].sum =(node[lchild].sum*node[i].mul+node[i].xor * (len - (len >> 1)))%MOD;
	node[rchild].sum =(node[rchild].sum*node[i].mul+node[i].xor * (len >> 1))%MOD;
	
	node[lchild].mul =(node[lchild].mul*node[i].mul)%MOD;
	node[rchild].mul =(node[rchild].mul*node[i].mul)%MOD;
	node[lchild].xor =(node[lchild].xor*node[i].mul+node[i].xor)%MOD;
	node[rchild].xor =(node[rchild].xor*node[i].mul+node[i].xor)%MOD;

	node[i].xor = 0;
	node[i].mul = 1;
}
inline void modify1(int i, ll x, ll y, ll t)
{
	ll l = node[i].l;
	ll r = node[i].r;
	if(x <= l && r <= y)
	{
		node[i].sum = (node[i].sum*t)%MOD;
		node[i].mul = (node[i].mul*t)%MOD; 
		node[i].xor = (node[i].xor*t)%MOD; 
		return;
	}
	pushdown(i);
	if(x <= mid)
		modify1(lchild, x, y, t);
	if(mid < y)
		modify1(rchild, x, y, t);
	update(i);
}
inline void modify2(int i, ll x, ll y, ll t)
{
	ll l = node[i].l;
	ll r = node[i].r;
	if(x <= l && r <= y)
	{
		node[i].sum = (node[i].sum+(r - l + 1) * t)%MOD;
		node[i].xor = (node[i].xor+t)%MOD;
		return;
	}
	pushdown(i);
	if(x <= mid)
		modify2(lchild, x, y, t);
	if(mid < y)
		modify2(rchild, x, y, t);
	update(i);
}

inline ll getsum(int i, ll x, ll y)
{
	ll l = node[i].l;
	ll r = node[i].r;
	if (x <= l && r <= y)
		return (node[i].sum+MOD)%MOD;
	pushdown(i);
	ll ans = 0;
	if(x <= mid)
		ans += getsum(lchild, x, y);
	if(mid < y)
		ans += getsum(rchild, x, y);
	return (ans+MOD)%MOD;
}
int main()
{
	ll n, m, p;
	scanf("%lld%lld%lld", &n, &m,&p);
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
			modify1(1, x, y, k%MOD);
		}
		else if(c==2)
		{
			scanf("%lld%lld%lld", &x, &y, &k);
			modify2(1, x, y, k%MOD);
		}
		else
		{
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", getsum(1, x, y));
		}
	}
	return 0;
}
