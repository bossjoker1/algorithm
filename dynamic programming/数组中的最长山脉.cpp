class Solution {
public:
    int longestMountain(vector<int>& arr) {
        // 拆分最长连续递增序列和最长连续递减序列
        // 求和
        // 注意输出为0的奇怪输入
        int n = arr.size();
        vector<int> dp1(n+1, 1), dp2(n+1, 1);
        
        for(int i = 2; i <= n; i++){
            if(arr[i-1] > arr[i-2])   dp1[i] = dp1[i-1] + 1;
        }
        for(int i = n-1; i>=1 ; i-- ){
            if(arr[i-1] > arr[i]) dp2[i] = dp2[i+1] + 1;
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            // 必须满足山脉
            if(dp1[i] > 1 && dp2[i] > 1){
                int sum = dp1[i] + dp2[i] - 1;
                ans = max(ans, sum);
            }
        }
        if(ans < 3) return 0;

        return ans;
    }
};