// 将至少k个连续的H可以转换为→至多n-k个连续→至多n个连续的情况数-至多(k-1)个连续的情况

// i<=x : dp[i][0]=dp[i-1][0]+dp[i-1][1]

// i==x+1 : dp[i][0]=dp[i-1][0]+dp[i-1][1]-1   因为第x+1的位置为H时 它前x个的情况就不要能为全为H的情况 故-1

// i>x+1 : dp[i][0]=dp[i-1][0]+dp[i-1][1]-dp[i-x-1][1]  

// 当i-1~i-x的位置全为H时 i的位置不能为H i-x-1一定为T，即排除第i-x-1次为反而且中间全是正的情况的情况

// 该方法超时
#include<bits/stdc++.h>
using namespace std;
#define ll long long
using namespace std;
const ll maxn=101;
ll a[maxn][3];
ll big[maxn];
int main()
{
    ll n,k;
    while(scanf("%lld%lld", &n, &k) == 2){
        big[1]=1;
        big[0]=1;
        for(ll i=1;i<=n;i++)
        {
            for(ll i=1;i<=big[0];i++)
                big[i]*=2;
            for(ll i=1;i<=big[0];i++)
            {
                if(big[i]>=10)
                {
                    big[i+1]+=big[i]/10;
                    big[i]%=10;
                }
                if(big[big[0]+1]>0)
                    big[0]++;
            }
        }

        if(k-1==0)
        {
            a[n][1]=0,a[n][2]=1;
            goto dog;
        }

        a[1][1]=1;a[1][2]=1;
        for(ll i=2;i<=n;i++)
        {
            a[i][2]=a[i-1][1]+a[i-1][2];

            if(i<=k-1)
                a[i][1]=a[i-1][1]+a[i-1][2];
            else if(i==k-1+1)
                a[i][1]=a[i-1][1]+a[i-1][2]-1;
            else
                a[i][1]=a[i-1][1]+a[i-1][2]-a[i-(k-1)-1][2];
        }
        dog:;
        big[1]-=a[n][1]+a[n][2];
        while(big[1]<0)
        {
            big[1]+=pow(10,big[0]-1);
            big[big[0]]--;
            if(big[big[0]]==1)
            {
                big[0]--;
            }
        }
        for(ll i=1;i<=big[0];i++)
        {
            if(big[i]>=10)
            {
                big[i+1]+=big[i]/10;
                big[i]%=10;
            }
            if(big[big[0]+1]>0)
                big[0]++;
        }
        for(ll i=big[0];i>=1;i--)
            printf("%lld",big[i]);
        }
    return 0;
}

