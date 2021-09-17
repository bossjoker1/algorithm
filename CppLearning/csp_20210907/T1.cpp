#include<bits/stdc++.h>
#define ll long long
#define db double
#define INF 0x3f3f3f3f3f3f3f3f
#define N 1001000
#define M 1000000007
using namespace std;

ll T,n,m,num[N],a[N],b[N],aa,bb;

int main()
{
	ll i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++) scanf("%lld",&num[i]);
	for(i=1;i<=n;i++)
	{
		if(num[i]&1) a[++aa]=num[i];
		else b[++bb]=num[i];
	}
	sort(a+1,a+aa+1);
	sort(b+1,b+bb+1);reverse(b+1,b+bb+1);
	for(i=j=k=1;i<=aa&&j<=bb;)
	{
		num[k++]=a[i++];
		num[k++]=b[j++];
	}
	for(;i<=aa;) num[k++]=a[i++];
	for(;j<=bb;) num[k++]=b[j++];
	cout<<num[m];
}


