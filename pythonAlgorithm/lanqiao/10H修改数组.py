# 并查集，向上压缩
N = int(input())
Arr = list(map(int, input().split()))

visited = [0] * 1100005

par = [0] * 1100005

def find(x:int)->int:
    if par[x] == x:
        return x
    else:
        par[x] = find(par[x])
        return par[x]
        
for i in range(1, 1100005):
    par[i] = i
    
for item in Arr:
    ans = item if not visited[item] else (find(item)+1)
    
    visited[ans] = 1
    
    print(ans, "", end="")
    
    # 并查集向上压缩
    # 祖先要比孩子大
    
    if ans != 1 and visited[ans-1]:
        par[ans-1] = ans
        
    if visited[ans + 1]:
        par[ans] = ans + 1