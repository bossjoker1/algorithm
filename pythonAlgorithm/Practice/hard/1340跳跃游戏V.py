# hard
# dp[i]表示以i为索引能跳跃的次数
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        # 按高度从低到高排序，并记录索引
        L = [(arr[i], i) for i in range(len(arr))]
        L = sorted(L, key=lambda x:x[0])
        n = len(arr)
        dp = [1] * n
        for h, i in L:
            cur = 1
            # 向左跳
            for idx in range(i - 1, max(0, i - d)-1, -1):
                if arr[idx] >= h:
                    # 有高的跳不过去，直接break
                    break
                cur = max(dp[idx] + 1,cur)
            # 向右跳
            for idx in range(i + 1, min(n, i + d + 1)):
                if arr[idx] >= h:
                    break
                cur = max(dp[idx] + 1, cur)
            dp[i] = cur
            
        return(max(dp))