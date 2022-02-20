# 卡最后一个样例的时间md
N = int(input())
W = list(map(int, input().split()))

s = set()

for i in range(N):
    for item in s.copy():
        if abs(W[i] - item):
            s.add(abs(W[i] - item))
        if abs(W[i] + item):
            s.add(abs(W[i] + item))
            
    s.add(W[i])
            
print(len(s))
        
