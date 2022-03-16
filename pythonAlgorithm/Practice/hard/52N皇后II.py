class Solution:
    def totalNQueens(self, n: int) -> int:
        # 标记：竖排，正对角线，反对角线
        hash1, hash2, hash3 = set(), set(), set()
        ans = 0
        def dfs(cur):
            nonlocal ans
            if cur == n:
                ans += 1
                return 
            for i in range(n):
                if (i not in hash1) and ((i+cur) not in hash2) and ((cur - i) not in hash3):
                    hash1.add(i)
                    hash2.add(i+cur)
                    hash3.add(cur-i)
                    dfs(cur + 1)
                    hash1.remove(i)
                    hash2.remove(i+cur)
                    hash3.remove(cur-i)           
        dfs(0)
        return ans