#include <stdio.h>
#include <string.h>
 
#define M 999999997

long long dp[1005][6];
 
int main(){
    int n;
    scanf("%d", &n);

    for(int i=1;i<=n;i++)
    {
        int j=i-1;
        dp[i][0]=1;
        dp[i][1]=(dp[j][0]+dp[j][1]*2)%M;
        dp[i][2]=(dp[j][0]+dp[j][2])%M;
        dp[i][3]=(dp[j][1]+dp[j][3]*2)%M;
        dp[i][4]=(dp[j][1]+dp[j][2]+dp[j][4]*2)%M;
        dp[i][5]=(dp[j][3]+dp[j][4]+dp[j][5]*2)%M;
    }

    printf("%lld\n", dp[n][5]);
    return 0;
}