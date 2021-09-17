//410
//自己写的方法O(n^2*m)，超出时间限制
class Solution {
public:

    int sum(vector<int> &ans, int k ,int j){
        return accumulate(ans.begin()+k-1, ans.begin()+j, 0);
    }

    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1;i <= n - (m-1);i++){
            dp[1][i] = sum(nums, 1, i);
            //cout<<"(1,"<<i<<"):"<<dp[1][i]<<"  ";
        }
        //cout<<endl;
        for(int i = 2; i <= m; i++){
            for(int j = i; j <= n - (m - i); j++){
                int minx = 0x7ffffff;
                for(int k = i; k <= j;k++){
                    int temp = sum(nums, k, j);
                    minx = min(max(temp, dp[i-1][k-1]), minx);
                }
                dp[i][j] = minx;
                //cout<<"("<<i<<","<<j<<"):"<<dp[i][j]<<"  ";
            }
            //cout<<endl;
        }
        return dp[m][n];
    }
};

//抄题解
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return (int)f[n][m];
    }
};


//二分查找要快很多 O(N*log(sum−maxn))

class Solution {
public:

    bool check(vector<int> ans, long target, int m){
        long  long sum = 0;
        int cnt = 1;
        for (int i = 0; i < ans.size(); i++){
            if(sum + ans[i] <= target){
                sum += ans[i];
            }else{
                cnt++;
                sum = ans[i];
                if(sum > target) return false;
            }
        }
        return cnt <= m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long l = 0, r = 0;
        int n = nums.size();
        //上下界
        r = accumulate(nums.begin(), nums.end(), 0);
        l = *max_element(nums.begin(), nums.end());

        while(l < r){
            long long mid = (l + r) >> 1;
            if(check(nums, mid, m)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};