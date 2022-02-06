# hard依旧没什么思路
# 前缀最小和 + 前缀最大和  (堆维护)

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        n, k = len(nums), len(nums) // 3
        s1, s2 = [0] * n, [0] * n
        q = []

        for i in range(2*k):
            if i: s1[i] = s1[i-1]
            heapq.heappush(q, -nums[i])
            s1[i] += nums[i]
            if len(q) > k:
                s1[i] -= -heapq.heappop(q)
        
        q.clear()

        for i in range(n-2, k-2, -1):
            s2[i] = s2[i+1]
            heapq.heappush(q, nums[i+1])
            s2[i] += nums[i+1]
            if len(q) > k:
                s2[i] -= heapq.heappop(q)

        res = sys.maxsize
        for i in range(k-1, 2*k):
            res = min(res, s1[i] - s2[i])

        return res

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