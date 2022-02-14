# G(n)表示n个节点构成的二叉搜索树的个数
# G(0) = G(1) = 1
# f(i)表示以第i个节点为根的二叉搜索树的个数
# G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n)
# f(i) = G(i-1)*G(n-i),
# G(n) = G(0)*G(n-1)+G(1)*G(n-2)+...+G(n-1)*G(0)

class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0] * (n+1)

        dp[0] = dp[1] = 1

        for i in range(2, n+1):
            for j in range(0, i):
                dp[i] += dp[j] * dp[i-j-1]

        return dp[n]