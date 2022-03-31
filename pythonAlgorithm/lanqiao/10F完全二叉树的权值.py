import math
from time import time


N = int(input())

nodes = list(map(int, input().split()))

k, maxv = -1, -math.inf

cur, depth = 0, 1
times = 1
while cur < N:
    temp = sum(nodes[cur: min(cur+times, N)])
    # print(temp)
    cur = cur + times
    times *= 2
    if maxv < temp:
        k = depth
        maxv = temp
        
    depth += 1
    
print(k)