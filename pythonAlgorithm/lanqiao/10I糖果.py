N, M, K = list(map(int, input().split()))
MAXN = 105
Ts = [0] * MAXN

for i in range(N):
    temp = list(map(int, input().split()))
    for j in range(K):
        Ts[i] |= 1 << (temp[j]-1)
    
# 每一个糖果包可以压缩成二进制，学到了
# f[s]表示糖果状态为s需要的最少包数
f = [127] * (1 << 20)

f[0] = 0

for i in range(N):
    for s in range(1<<M):
        # 该状态不可达
        if f[s] > MAXN:
            continue
        # 取最小值
        f[s | Ts[i]] = min(f[s | Ts[i]], f[s] + 1)
        
        
res = f[(1<<M)-1] if f[(1<<M)-1] < MAXN else -1

print(res)