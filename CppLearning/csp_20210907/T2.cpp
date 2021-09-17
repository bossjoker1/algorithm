#include<bits/stdc++.h>
#define ll long long
#define db double
#define INF 0x3f3f3f3f3f3f3f3f
#define N 5
#define M 2021
using namespace std;

ll T,n=3,m;
struct Jz
{
	ll num[N][N];
	Jz(){memset(num,0,sizeof(num));}
	Jz operator * (const Jz &u) const
	{
		ll i,j,k;
		Jz res;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
				{
					res.num[i][j]+=num[i][k]*u.num[k][j];
					res.num[i][j]%=M;
				}
			}
		}
		return res;
	}
}dw,a;

inline Jz po(Jz u,ll v)
{
	ll i;
	Jz res;
	for(i=1;i<=n;i++) res.num[i][i]=1;
	for(;v;)
	{
		if(v&1) res=res*u;
		u=u*u;
		v>>=1;
	}
	return res;
}

int main()
{
	ll i,j,k;
	cin>>m;
	for(i=1;i<n;i++) dw.num[i+1][i]=dw.num[i][n]=1;dw.num[n][n]=1;
	a.num[1][1]=a.num[1][2]=1,a.num[1][3]=2;
	a=a*po(dw,m);
	cout<<a.num[1][1];
}
