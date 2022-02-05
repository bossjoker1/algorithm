# hard依旧没什么思路

# 贴个题解，明天再看
# class Solution {
# public:
#     long long minimumDifference(vector<int>& nums) {
#         int n = nums.size() / 3;
#         priority_queue<int> que;
#         vector<long long> A(n * 3), B(n * 3);
#         long long ans = 1e18;
#         long long sum = 0;
#         for (int i = 0; i < n; ++i) {
#             sum += nums[i];
#             que.push(nums[i]);
#         }
#         A[n - 1] = sum;
#         for (int i = n; i < n * 3; ++i) {
#             if (nums[i] < que.top()) {
#                 sum -= que.top();
#                 que.pop();
#                 que.push(nums[i]);
#                 sum += nums[i];
#             }
#             A[i] = sum;
#         }
#         sum = 0;
#         while (que.size())
#             que.pop();
#         for (int i = n * 3 - 1; i >= n * 2; --i) {
#             sum += nums[i];
#             que.push(-nums[i]);
#         }
#         B[n * 2] = sum;
#         for (int i = n * 2 - 1; i >= 0; --i) {
#             // cout << i << " " << nums[i] << " " << que.top() << endl;
#             if (nums[i] > -que.top()) {
#                 sum -= -que.top();
#                 que.pop();
#                 que.push(-nums[i]);
#                 sum += nums[i];
#             }
#             B[i] = sum;
#         }
#         for (int i = n - 1; i < n * 2; ++i) {
#             // cout << i << " " << A[i] << " " << B[i + 1] << endl;
#             ans = min(ans, A[i] - B[i + 1]);
#         }
#         return ans;
#     }
# };