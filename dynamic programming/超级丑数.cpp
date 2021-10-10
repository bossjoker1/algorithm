// 三指针 => 多指针
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size(), plist[k], dp[n];
        memset(plist, 0, sizeof(plist)); // 各素数对应的索引
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            int low = INT_MAX;
            for(int i = 0; i < k; i++){
                low = min(low, primes[i] * dp[plist[i]]);
            }
            dp[i] = low;
            for(int i = 0; i < k; i++){
                if(primes[i] * dp[plist[i]] == low){
                    plist[i]++;
                }
            }
        }
        return dp[n-1];
    }
};