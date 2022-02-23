class Solution:
    def countEven(self, num: int) -> int:
        
        def isRight(n:int)->bool:
            s = 0
            while n:
                s +=  (n % 10)
                n //= 10
            return True if s % 2 == 0 else False
        cnt = 0
        for i in range(1, num+1):
            if isRight(i):
                cnt += 1

        return cnt
