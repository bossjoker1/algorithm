# 官解
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = [0] * n
        num = 1
        for i in range(n):
            ans[i] = num
            if num * 10 <= n:
                num *= 10
            else:
                # 末尾数字已经枚举完
                # 退回到上一位
                # eg : n = 10009, 10009 => 1001
                while num % 10 == 9 or num + 1 > n:
                    num //= 10
                num += 1
        return ans

# 深度优先搜索
# 可以视作贪心，把字典序小的且≤n的情况先排完
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        self.ans = []
        def dfs(cur):
            if cur > n:return
            self.ans.append(cur)
            for i in range(0, 10): dfs(cur * 10 + i)
        
        for j in range(1, 10): dfs(j)
        return self.ans