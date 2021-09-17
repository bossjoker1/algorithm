#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200100
using namespace std;
 
ll T,n,m,S,ans,num[N],nxt[N],to[N],cst[N],lk[N];
map<ll,ll>pos;

int main()
{
	ll i,j,k,p,q,t;
	cin>>n;
	S=sqrt(n);
	for(i=1;i<=n;i++) scanf("%lld",&num[i]),pos[num[i]]=n+1;
	for(i=n;i>=1;i--)
	{
		nxt[i]=pos[num[i]];
		pos[num[i]]=i;
	}
//	for(i=1;i<=n;i++) cout<<nxt[i]<<" ";return 0;
	for(i=(n+S-1)/S;i>=1;i--)
	{
		p=(i-1)*S+1,q=min(n,i*S);
//		cout<<" "<<p<<" "<<q<<endl;
		for(j=q;j>=p;j--)
		{
			t=INF;
			for(k=j;k<=q;k++)
			{
				if(k==t)
				{
					to[j]=to[k];
					cst[j]=cst[k]+1;
					lk[j]=k;
					break;
				}
				t=min(t,nxt[k]);
			}
			if(k>q)
			{
				if(k==n+1) to[j]=lk[j]=n+1,cst[j]=1;
				else
				{
//					if(j==4) cout<<k<<"  "<<t<<"  "<<to[k]<<endl;
					if(t<lk[k]) to[j]=lk[j]=t,cst[j]=1;
					else to[j]=to[k],lk[j]=lk[k],cst[j]=cst[k];
				}
			}
		}
	}
//	for(i=1;i<=n;i++) cout<<i<<":"<<lk[i]<<" "<<to[i]<<" "<<cst[i]<<endl;return 0;
	cin>>m;
	while(m--)
	{
		ans=0;
		scanf("%lld%lld",&p,&q);
		for(i=p;to[i]<=q;i=to[i]) ans+=cst[i];
		for(;i<=q;i=lk[i]) ans++;
		printf("%lld\n",ans);
	}
}
/*
10
5 8 5 5 8 4 3 9 9 5 
1
3 9
*/
