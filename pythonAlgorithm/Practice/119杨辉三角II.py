class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        pre = [1]
        for i in range(2, rowIndex+2):
            res = []
            for j in range(i):
                if j == 0 or j == i-1 :
                    res.append(1)
                else:
                    res.append(pre[j-1] + pre[j])
            pre = res

        return pre
    
# 滚动数组压缩
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        dp = [1] * (rowIndex + 1)
        for i in range(2, len(dp)):
            for j in range(i-1, 0, -1):
                dp[j] = dp[j] + dp[j-1]
        return dp
