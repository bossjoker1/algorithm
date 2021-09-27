#include<stdio.h>

typedef long long ll;

ll dp[55] = {0};

int main() {
    int n, a, b;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);

        for(int j = b; j>0;j--){
            if(j == b-1){
                dp[j] = 1;
            }else if( j == b-2){
                dp[j] = 2;
            }
            else{
                dp[j] = dp[j+1] + dp[j+2];
            }
        }
        printf("%d\n", dp[a]);
    }
    return 0;
}