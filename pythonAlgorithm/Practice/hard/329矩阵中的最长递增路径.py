# hard?
# 记忆化dfs

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        @lru_cache(None)
        def dfs(x,y):
            ans = 1
            for dx,dy in [(-1,0),(1,0),(0,1),(0,-1)]:
                xx,yy = x+dx,y+dy
                if 0<=xx<m and 0<=yy<n and matrix[xx][yy]>matrix[x][y]:
                    ans = max(ans,dfs(xx,yy)+1)
            return ans

        res,m,n = 0,len(matrix),len(matrix[0])
        for i in range(m):
            for j in range(n):
                res = max(res,dfs(i,j))
        return res