import math
import sys

n = 2021

edges = [[] for _ in range(2022)]



for i in range(1, n+1):
    for j in range(i+1, min(2022, i+22)):
        edges[i].append((j, i * j // math.gcd(i, j)))


dis = [sys.maxsize] * 2022
vis = [0] * 2022
vis[1] = 1
for item in edges[1]:
    dis[item[0]] = item[1]


for i in range(1, 2021):
    minv, k = sys.maxsize, -1
    for edge in edges[i]:
        if not vis[edge[0]] and dis[edge[0]] < minv:
            minv = dis[edge[0]]
            k = edge[0]
    
    vis[edge[0]] = 1
    
    for edge in edges[k]:
        val = minv + edge[1]
        dis[edge[0]] =min(dis[edge[0]], val)

# 10266837
print(dis[2021])
        