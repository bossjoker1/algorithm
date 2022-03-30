N = 20190324
MOD = 10000
l, m, r = 1, 1, 1

for i in range(4, N+1):
    t = r
    r = (r + l + m) % MOD
    l = m
    m = t
    
# 稍微花点时间:
# 4659  
print(r)