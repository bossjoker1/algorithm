class Solution:
    def digArtifacts(self, n: int, artifacts: List[List[int]], dig: List[List[int]]) -> int:
        def check(bao):
            x, y, a, b = bao
            d1 = a - x
            d2 = b - y
            for i in range(d1+1):
                for j in range(d2+1):
                    if not dp[x+i][y+j]:
                        return False
            return True
            
        
        res = 0
        dp = [[0] * n for _ in range(n)]
        
        for i in range(len(dig)):
            x, y = dig[i]
            dp[x][y] = 1
            
            
        for i in range(len(artifacts)):
            if check(artifacts[i]):
                res += 1
                
        return res