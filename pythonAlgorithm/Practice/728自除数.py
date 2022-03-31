class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        res = []
        def check(x:int)->bool:
            t = x
            while t:
                if t%10 == 0 or x % ( t%10) != 0:
                    return False
                t //= 10
            return True


        for i in range(left, right+1):
            if check(i):
                res.append(i)

        return res