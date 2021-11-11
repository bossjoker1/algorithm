#include<bits/stdc++.h>
using namespace std;
const int 
	N=1005,
	inf=10000000;
int m,n,x[N],y[N],abi[505];
int dis[N],Map[N][N];
bool vis[N];
int Prim(){
	int ans=0;
	for (int i=1;i<=n;i++) dis[i]=Map[1][i];
	vis[1]=1;
	for (int i=1;i<n;i++){
		int Min=inf,mi=0;
		for (int j=1;j<=n;j++)
			if (!vis[j] && Min>dis[j]) Min=dis[j],mi=j;
		vis[mi]=1;
		ans=max(ans,Min);
		for (int j=1;j<=n;j++)
			if (dis[j]>Map[mi][j]) dis[j]=Map[mi][j];
	}
	return ans;
}
int main(){
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d",&abi[i]);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			Map[i][j]=Map[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	int t=Prim(),ans=0;
	for (int i=1;i<=m;i++)
		if (abi[i]*abi[i]>=t) ans++;
	printf("%d\n",ans);
	return 0;
}