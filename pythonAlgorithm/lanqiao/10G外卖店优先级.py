N, M, T = list(map(int, input().split()))

q = [[] for _ in range(100005)]

for i in range(M):
    t, v = list(map(int, input().split()))
    q[v].append(t)

res = 0

for i in range(1, N+1):
    if len(q[i]) == 0:
        continue
    q[i].sort()
    cnt = 0
    pre = 0
    for t in q[i]:
        if t -1 - pre > 0:
            cnt -= (t - 1 - pre)
        cnt = max(0, cnt)
        cnt += 2
        pre = t

    cnt -= (T - pre)
    # print(cnt)
    if cnt > 3 and (cnt > 5 or (cnt == 5 and q[i][-1] != T) or (cnt == 4 and q[i][-1] < T-1)):
        res+=1
        

print(res) 