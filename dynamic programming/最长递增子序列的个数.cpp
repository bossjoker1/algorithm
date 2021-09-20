// 标签里还有树状数组和线段树，提供了优化的方向
// 这两个只能说不太熟，只会做些查改
// 相关题目有个最长连续子序列简单题，秒杀

// dp[i]表示以num[i]结尾的递增子序列的长度
// cnt[i]表示以num[i]结尾的递增序列的个数
// 最后的结果就是dp[i] == max_len的cnt[i]之和
// dp[i] = max(dp[j]) + 1    (j < i && nums[j]<nums[i])
class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size(), maxLen = 0, ans = 0;
        vector<int> dp(n), cnt(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
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
        return ans;
    }
};

// 二分查找