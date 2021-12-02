#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

// 首先 对于方案二和方案四都不能和其他方案共用，那么就取较小值，把他俩看成一个；
// 那么dp[i][j]表示前i个数 用方案二和方案三总时间为j的时候剩余的用方案一的最短时间；

int dp[45][405];
int main() 
{
	int n;
	scanf("%d", &n);
	memset(dp, 0x3f, sizeof dp);
	memset(dp[0], 0, sizeof dp[0]);
	for(int i = 1;i <= n;i ++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		b = min(b, d);
		for(int j = 0;j <= 400;j ++)
		{
			dp[i][j] = dp[i-1][j] + a;  // 采取方案一； 
			if(j >= b)dp[i][j] = min(dp[i][j], dp[i-1][j-b]+b); // 采取不能和其他人一起的方案，那么总体升高b； 
			if(j >= c)dp[i][j] = min(dp[i][j], dp[i-1][j-c]);   // 采取方案三； 
		}
	}
	int ans = 0x3f3f3f3f;
	for(int i = 0;i <= n*10;i ++)
		ans = min(ans, max(dp[n][i], i));   
	cout<<ans<<endl;
	return 0;
}
