# 找规律
# 761
m, n = int(input()), int(input())

res = 1
for i in range(1, m):
    res += 4*i
    
print(res)