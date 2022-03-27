# 水题

grades = []
N = int(input())
minv, maxv = 101, -1
s = 0
for _ in range(N):
    t = int(input())
    minv = min(t, minv)
    maxv = max(t, maxv)
    s += t

print(maxv)
print(minv)
print("%.2f"%(s/N))