#include <stdio.h>

typedef long long ll;
ll dp[60] = {0};

int main(){
    int n;

    dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 4;

    while(1){
        scanf("%d", &n);
        if(n == 0) break;

        if(dp[n] > 0) {
            printf("%d\n", dp[n]);
            continue;
        }

        for(int i = 5; i <= n ;i++){
            dp[i] = dp[i-1] + dp[i-3];
        }

        printf("%d\n", dp[n]);
    }

    return 0;
}