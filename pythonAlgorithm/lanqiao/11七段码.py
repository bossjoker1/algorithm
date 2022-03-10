from collections import defaultdict

g = defaultdict(list)

g[1].extend([2,6])
g[2].extend([1,3,7])
g[3].extend([2,4,7])
g[4].extend([3,5])
g[5].extend([4,6,7])
g[6].extend([1,5,7])
g[7].extend([2,3,5,6])


par = [i for i in range(8)]

def find(x:int):
    if par[x] == x:
        return x
    else:
        par[x] = find(par[x])
        return par[x]
    
def unite(x:int, y:int):
    x = find(x)
    y = find(y)
    if x == y:
        return 
    else:
        par[x] = par[y]


def check(temp):
    for i in range(len(temp)):
        for j in range(len(temp)):
            if temp[j] in g[temp[i]]:
                unite(temp[i], temp[j])
    k = 0
    for item in temp:
        if par[item] == item:
            k += 1
    if k == 1:
        return True
    else:
        return False
        
num = 1 << 7
res = 0
for mask in range(1, num):
    temp = []
    par = [i for i in range(8)]
    for i in range(7):
        if (mask >> i) & 1:
            temp.append(i+1)   
    if check(temp):
        res += 1
print(res)