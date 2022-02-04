# 只想到动态规划解
# 甚至一开始还以为套下最长重复子串就行了
# 发现子串不连续，子数组连续，后者稍微复杂一点点

class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        # dp[i+1][j+1]表示A[i]和B[j]为最右界时，子数组的最长长度
        # 为0时表示不行，需要另启起点
        # 转移方程：
        m, n = len(nums1), len(nums2)
        dp = [[0]*(n+1) for _ in range(m+1)]
        cnt = 0
        for i in range(m):
            for j in range(n):
                if nums1[i] == nums2[j]:
                    dp[i+1][j+1] = dp[i][j] + 1
                    cnt = max(cnt, dp[i+1][j+1])
        return cnt
    

# 滑动窗口解法 java
# class Solution {
#     public int findLength(int[] nums1, int[] nums2) {
#         return Math.max(maxLen(nums1,nums2),maxLen(nums2,nums1));
#     }
#     public int maxLen(int[] nums1,int[] nums2){
#         int ans=0;
#         for(int i=0;i<nums1.length;i++){
#             int max=0;
#             int temp=0;
#             for(int j=0;j<nums2.length&&i+j<nums1.length;j++){
#                 if(nums1[j+i]==nums2[j])
#                     temp++;
#                 else
#                     temp=0;
#                 max=Math.max(temp,max);
#             }
#             ans=Math.max(max,ans);
#         }
#         return ans;
#     }
# }