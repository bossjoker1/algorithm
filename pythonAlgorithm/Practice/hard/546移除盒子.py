# 记忆化搜索更便于理解

class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:

        n = len(boxes)

        dp = [[[0]*n for _ in range(n)] for _ in range(n)]

        def helper(l,r,k): # 删除区间[l,r]和r右侧k个a[r]的积分
            if l>r:
                return 0
            if dp[l][r][k]!=0:
                return dp[l][r][k]
            while r>l and boxes[r]==boxes[r-1]:    # 找到尾巴重复数的个数，这个时候a[r]为重复数，
                r -= 1                             # 如果尾巴不是重复，这里的k不会变
                k += 1
            
            dp[l][r][k] = helper(l,r-1,0)+(k+1)*(k+1)   # 移除a[r]和k个a[r]

            for i in range(l,r):
                if boxes[i]==boxes[r]:    # 移除a[i]和k个a[r]共(k+1)个相同的, 移除i,r之间的数,再移除剩下的
                    dp[l][r][k] = max(dp[l][r][k],helper(l,i,k+1)+helper(i+1,r-1,0))
            return dp[l][r][k]
        return helper(0,n-1,0)

class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        n = len(boxes)
        dp = [[[0] * n for _ in range(n)] for _ in range(n)]
        for l in range(n-1,-1,-1):
            for r in range(l,n):
                for k in range(n-r):
                    if r > l and boxes[r] == boxes[r-1]:
                        dp[l][r][k] = dp[l][r-1][k+1]
                        continue
                    dp[l][r][k] = dp[l][r-1][0] + (k+1)**2
                    for i in range(l, r):
                        if boxes[i] == boxes[r]:
                            # 移除 i+1 ~ r-1 然后 i 和 r拼成了(k+1)个连续的 
                            dp[l][r][k] = max(dp[l][r][k], dp[l][i][k+1] + dp[i+1][r-1][0])
        return dp[0][n-1][0]