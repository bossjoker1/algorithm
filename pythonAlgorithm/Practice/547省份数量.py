# 老并查集了

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        par = [i for i in range(n)]

        def find(x:int):
            if par[x] == x:
                return x
            else:
                par[x] = find(par[x])
                return par[x]
            
        def unite(x:int, y:int):
            x = find(x)
            y = find(y)
            if x == y:
                return 
            else:
                par[x] = par[y]

        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                if isConnected[i][j] == 1:
                    unite(i, j)
        cnt = 0
        for i in range(n):
            if par[i] == i:
                cnt += 1

        return cnt
    
# 深搜

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def dfs(i: int):
            for j in range(provinces):
                if isConnected[i][j] == 1 and j not in visited:
                    visited.add(j)
                    dfs(j)
        
        provinces = len(isConnected)
        visited = set()
        circles = 0

        for i in range(provinces):
            if i not in visited:
                dfs(i)
                circles += 1
        
        return circles
