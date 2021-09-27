#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;

int main() {
    int n, M;
    scanf("%d",&n);
    vector<int> dp(41, 0);
    dp[0] = dp[1] = 1;
    for(int i = 0; i < n; i++){
        scanf("%d",&M);
        if(M == 1){
            printf("0\n");
            continue;
        }
        M--;

        if(dp[M] > 0){
            printf("%d\n", dp[M]);
            continue;
        }

        for(int i = 2; i <= M;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        printf("%d\n", dp[M]);
        
    }
    return 0;
}