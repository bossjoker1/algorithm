// https://blog.csdn.net/Daniel__d/article/details/102829172?utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.no_search_link&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.no_search_link

// 四边形不等式优化


// for (int len = 2; len <= n; ++len)  // 枚举区间长度
//   for (int l = 1, r = len; r <= n; ++l, ++r) {
//     // 枚举长度为len的所有区间
//     f[l][r] = INF;
//     for (int k = m[l][r - 1]; k <= m[l + 1][r]; ++k)
//       if (f[l][r] > f[l][k] + f[k + 1][r] + w(l, r)) {
//         f[l][r] = f[l][k] + f[k + 1][r] + w(l, r);  // 更新状态值
//         m[l][r] = k;  // 更新（最小）最优决策点
//       }
//   }

#include<bits/stdc++.h>
#define INF 1e18
using namespace std;
long long f[5011][5011],sum[5100],n;
int g[5011][5011],v;
inline long long read()
{
	long long f=1,re=0;
	char ch;
	for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	for(;(ch>='0'&&ch<='9');ch=getchar())
		re=(re<<3)+(re<<1)+ch-'0';
	return re*f;
}
signed main()
{
	long long x;
	n=read();
	for(int i=1;i<=n;i++)
	{
		x=read();
		sum[i]=sum[i-1]+x;
		f[i][i]=x;
		g[i][i]=i;
	}
	for(int i=1;i<n;i++)
		for(int j=1;(v=j+i)<=n;j++)
		{
			f[j][v]=INF;
			for(int k=g[j][v-1];k<=g[j+1][v];k++)
				if(f[j][v]>f[j][k-1]+f[k+1][v])
				{
					f[j][v]=f[j][k-1]+f[k+1][v];
					g[j][v]=k;
				}
			f[j][v]+=(sum[v]-sum[j-1]);
		}
	printf("%lld",f[1][n]);
	return 0;
}



