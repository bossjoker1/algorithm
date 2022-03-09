# 2481215

from math import gcd

T = 2021
cnt = 0
for i in range(1, T):
    for j in range(1, T):
        if gcd(i, j) == 1:
            cnt += 1
            
print(cnt)
        