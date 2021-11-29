#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
const int N=5e5+10,mod=1e9+7;

void add(int &a,LL b){a=(a+b)%mod;return ;}
PII a[N];
bool dis[N]; 

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].first),a[i].second=i;
	sort(a+1,a+n+1);
	int ma=0,cnt=0;
	for(int i=n;i>=0;i--) 
	{
		int x=a[i].first,y=a[i].second;
		if(x!=a[i+1].first)ma=max(ma,cnt);
		
		if(dis[y-1]&&dis[y+1]) cnt--;
		else if(!dis[y-1]&&!dis[y+1])cnt++;
		dis[y]=1;
	}
	printf("%d",ma);
	return 0;
}
