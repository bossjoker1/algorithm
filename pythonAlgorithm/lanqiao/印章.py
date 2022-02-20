# 转化为盒子问题，1 - P(至少一个为空)
import math
n, m = map(int, input().split())
C = math.comb
# if n > m:
# 	print('0.0000')
ans = sum([(-1) ** i * C(n, n - i) * (n - i) ** m for i in range(0, n)]) / n ** m
# print(f"{ans:.4f}")
print("%.4f"%ans)