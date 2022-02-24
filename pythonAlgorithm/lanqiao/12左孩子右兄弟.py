T = int(input())
childs = [[] for _ in range(T+1)]

for i in range(2, T+1):
    par = int(input())
    childs[par].append(i)
    
def dfs(x:int):
    ret = 0
    for item in childs[x]:
        temp = dfs(item) + len(childs[x])
        ret = max(ret, temp)
        
    return ret

print(dfs(1))
    