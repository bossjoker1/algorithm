#include <bits/stdc++.h>

using namespace std;

inline int read(){
    int x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

const int maxn = 2e5 + 5;
const int N = 5000 + 10;
const int INF = 0x3f3f3f3f;

struct edge{
	int to,dis,next;
}e[maxn<<1];

int n,m,head[N],dis[N],cnt,num,sum;
bool vis[maxn];

void add(int u,int v,int d)
{
	e[++cnt].dis = d;
	e[cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

struct node{
	int index,dist;
	node(int a,int b){
		index = a,dist = b;
	}
	bool operator < (const node &x) const{
		return dist > x.dist;
	}
};

bool prim()
{
	for(int i = 1; i <= n; i++)		dis[i] = INF,vis[i] = false;
	dis[1] = 0;
	
	priority_queue <node> q;
	q.push(node(1,0));
	
	int num = 0;
	
	while(!q.empty() && num < n)
	{
		node temp = q.top();
		q.pop();
		
		int x = temp.index, d = temp.dist;
		if(vis[x])	continue;
		vis[x] = true;
		num++;
		sum += d;
		for(int i = head[x]; i ; i = e[i].next){
			int y = e[i].to;
			if(dis[y] > e[i].dis){
				dis[y] = e[i].dis;
				q.push(node(y,dis[y]));
			}
		}
	}
    if(num < n){
        printf("orz\n");
		return false;
    }

	return true;
}

int main()
{
	n = read(), m = read();
	for(int i = 1; i <= m; i++){
		int u,v,d;
		u = read(), v = read(), d = read();
		add(u,v,d);
		add(v,u,d);
	}
	
	bool flag = prim();
	
	if(flag){
		printf("%d\n",sum);
	}
	return 0;
}
