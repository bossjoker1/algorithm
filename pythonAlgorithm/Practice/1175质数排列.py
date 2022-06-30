MOD = int(1e9+7)
class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        def isPrime(n):
            if n == 1:
                return False
            for i in range(2, int(math.sqrt(n)) + 1):
                if n % i == 0:
                    return False
            return True
        cnt = 0
        for i in range(1,n+1):
            if isPrime(i):
                cnt += 1
        nocnt = n - cnt
        res = 1
        # print(cnt, nocnt)
        for i in range(1, nocnt+1):
            res = (res * i) % MOD
        for i in range(1, cnt+1):
            res = (res * i) % MOD

        return res