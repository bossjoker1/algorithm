#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;

int main() {

    int n;
    ll maxLen = 0, ans = 0;
    vec nums;
    scanf("%d",&n);

    for(int i = 0; i < n ; i++){
        ll temp;
        scanf("%lld", &temp);
        nums.push_back(temp);
    }

    vec dp(n), cnt(n);

    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        cnt[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[i] < nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j]; // 重置计数
                } else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            ans = cnt[i]; // 重置计数
        } else if (dp[i] == maxLen) {
            ans += cnt[i];
        }
    }
    printf("%lld %lld", maxLen, ans);

    return 0;
}