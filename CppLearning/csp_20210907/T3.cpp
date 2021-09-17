#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define C ch=getchar()
#define INF 0x3f3f3f3f3f3f3f3f
#define N 1001000
#define M 5001000
using namespace std;

int T,n,m,bb,first[N];
ll sum,d[N];
bool in[N];
char ch;
struct Bn
{
	int to,quan,next;
}bn[M<<1];
vector<ll>have[N];
queue<int>que;
priority_queue<ll,vector<ll>,greater<ll> >pq2;

inline int read()
{
	for(C;ch<'0' || ch>'9';C);
	int res=ch-'0';
	for(C;ch>='0' && ch<='9';C) res=res*10+ch-'0';
	return res;
}

inline void add(int u,int v,int w)
{
	bb++;
	bn[bb].to=v;
	bn[bb].quan=w;
	bn[bb].next=first[u];
	first[u]=bb;
}

inline bool cmp(P u,P v){return u.se<v.se;}
int main()
{
	memset(d,0x3f,sizeof(d));
	memset(first,-1,sizeof(first));
	ll i,j,k,p,q,o,t;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		p=read(),q=read(),o=read();
		add(p,q,o),add(q,p,o);
	}
	d[0]=0;
	que.push(0);
	for(;!que.empty();)
	{
		int now=que.front();
		que.pop();
		in[now]=0;
		for(p=first[now];p!=-1;p=bn[p].next)
		{
			q=bn[p].to;
			t=d[now]+bn[p].quan;
			if(t>=d[q]) continue;
			d[q]=t;
			if(!in[q])
			{
				in[q]=1;
				que.push(q);
			}
		}
	}
//	for(i=1;i<=n;i++) cout<<d[i]<<' ';puts("");
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&t);
		have[t].push_back(d[i]);
		sum+=d[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<have[i].size();j++) pq2.push(have[i][j]);
		for(;pq2.size()>i;)
		{
			sum-=2*pq2.top();
			pq2.pop();
		}
	}
	cout<<sum;
}
