# 直接基于车锁
# 202 + 201 + 200 + 20 + 1 = 624
# 或者遍历
T = 2020
cnt = 0
for i in range(1, 2021):
     while i:
         temp = i % 10
         if temp == 2:
             cnt += 1
         i //= 10
print(cnt)