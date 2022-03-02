import math
n = 2021041820210418

def isPrime(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

ans = []
def Facture(n):
    while n:
        for i in range(2, int(math.sqrt(n)) + 1):
            if isPrime(i) and n % i == 0:
                ans.append(i)
                n //=  i
                break
        if isPrime(n):
            ans.append(n)
            return

# 质因数分解得
# [2, 3, 3, 3, 17, 131, 2857, 5882353]
# 2 17 131 2857 5882353 放到3个位置，有 3^5种
# 3个3可以分 3 0 0  | 1 2 0 | 1 1 1 共10种方法
# 都是质数，不可能出现重复值
# 故结果为 3^5 * 10 = 2430    
Facture(n)           
print(ans)
                


        