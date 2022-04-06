primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
hashmap = defaultdict(int)
for item in primes:
    hashmap[item] = 1
class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        res = 0
        for x in range(left, right + 1):
            cnt = 0
            while x:
                x -= (x & -x)
                cnt += 1
            # print(cnt)
            if hashmap[cnt]:
                res += 1

        return res

# 我的lj写法
class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        
        def isPrime(n:int)->bool:
            if n < 2:
                return False
            for i in range(2, int(math.sqrt(n)) + 1):
                if n % i == 0:
                    return False
            return True
        
        res = 0
        for i in range(left, right+1):
            cnt = 0
            while i:
                if (i & 1) == 1:
                    cnt += 1
                i >>= 1
            if isPrime(cnt):
                res+=1

        return res