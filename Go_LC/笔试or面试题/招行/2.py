from collections import Counter

N, K = list(map(int, input().split()))
A = list(map(int, input().split()))

A.sort()
c = Counter(A)
res = 0

q = []

for k, v in c.items():
    q.append(k)
    
n = len(q)


cnt, idx = 0, 0
for i in range(n):
    if q[i] - q[idx] > K:
        # print("plus")
        if c[q[i]] >= cnt:
            idx = i
            res = cnt
        else:
            res += c[q[i]] 
            
    cnt += c[q[i]]
        
print(res)