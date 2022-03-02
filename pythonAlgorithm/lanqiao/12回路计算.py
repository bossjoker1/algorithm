# dp[state][pos]，表示在当前点下已经经过的点的状态（包括当前点）
# 状压dp
import math


n = 21
m = 1 << 21
dp = [[0] * 21 for _ in range(m)]
dp[1][0] = 1

g = [[False] * 22 for _ in range(22)]

for i in range(1, 22):
    for j in range(1, 22):
        if math.gcd(i, j) == 1:
            g[i][j] = True


for mask in range(m):
    for i in range(21):
        if ((mask >> i) & 1):
            for k in range(21):
                # 可由哪个前置状态转移过来
                if (mask - (1<<i))>>k & 1 and g[i+1][k+1]:
                    dp[mask][i] += dp[mask - (1 << i)][k]
                    
ans = 0
# 累加遍历了所有点，且在2~21上的
# 因为1和所有其它点互质，即都可以回到1点
for i in range(1, 21):
    ans += dp[m-1][i]
    
print(ans)