#include<bits/stdc++.h>
using namespace std;
long long f[4010][4010],sum[4010], temp[4010],n;
int v;

typedef long long ll;
inline ll max(ll x,ll y){return x>y?x:y;}

inline ll read(){
    ll x=0,f=1;char ch=' ';
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return f==1?x:-x;
}

int main()
{
	ll n = read();
    // 环形直接拓展成2n的长度
	for(int i=1;i<=n;i++)
	{
		temp[i] = read();
		sum[i]= sum[i-1] + temp[i];
        temp[i+n] = temp[i];
	}
    for(int i = n+1; i<= 2*n; i++){
        sum[i] = sum[i-1] + temp[i];
    }
	for(int i=1;i<n;i++){
		for(int j=1;(v=j+i)<=2*n;j++)
		{
			f[j][v] = max(f[j+1][v], f[j][v-1]);
			f[j][v] += (sum[v]-sum[j-1]);
		}
    }
    int ans = -1;
    for(int i = 1; i<=n; i++){
        ans = max(ans, f[i][i+n-1]);
    }
	printf("%d\n",ans);
	return 0;
}