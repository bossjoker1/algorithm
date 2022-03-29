class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        res = 1
        dirs = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        
        def getNum(x:int) -> int:
            cnt = 0
            while x:
                cnt += x % 10
                x //= 10
            return cnt

        flag = set()
        
        def dfs(x, y):
            # print(x,y)
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0<=nx<m and 0<=ny<n and getNum(nx) + getNum(ny) <= k and (nx, ny) not in flag:
                    flag.add((nx, ny))
                    dfs(nx, ny)
            return


        flag.add((0, 0))
        dfs(0, 0)
        return len(flag)
