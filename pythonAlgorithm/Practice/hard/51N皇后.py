class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        # 标记：竖排，正对角线，反对角线
        hash1, hash2, hash3 = set(), set(), set()
        ans = [] 
        def dfs(cur, temp):
            if cur == n:
                # 浅拷贝麻了
                ans.append(temp.copy())
                # print(ans)
                return 
            for i in range(n):
                if (i not in hash1) and ((i+cur) not in hash2) and ((cur - i) not in hash3):
                    hash1.add(i)
                    hash2.add(i+cur)
                    hash3.add(cur-i)
                    temp.append("".join(["Q" if x == i else "." for x in range(n)]))
                    dfs(cur + 1, temp)
                    temp.pop()
                    hash1.remove(i)
                    hash2.remove(i+cur)
                    hash3.remove(cur-i)           
        dfs(0, [])
        return ans