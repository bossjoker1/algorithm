class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        dp = [[0]*(n+1) for _ in range(m+1)]

        # dp[i][j] 表示num1[:i], num2[:j]的最大连线数
        # 不相交的线其实就是限制了不能回头，换句话说就是上升的子序列问题
        for i in range(1, m+1):
            for j in range(1, n+1):
                if nums2[j-1] == nums1[i-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])

        # print(dp)
        return dp[m][n]
