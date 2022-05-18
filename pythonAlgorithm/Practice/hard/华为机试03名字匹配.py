# zhang gao, zhang ao gao, zhang hao guo, zhang san, zhong ao gao, tian mei, zhang bu shan, zhang bo si
# zhag

# 艹，明明可以水几分的

names = list(map(str, input().strip().split(',')))

fstr = input()

m, n = len(names), len(fstr)

items = [[] for _ in range(m)]

for i in range(m):
    items[i] = names[i].strip().split()
# print(names)   
# print(items)
    
res = []

for cur in items:
    flag = False
    clen = len(cur)
    if clen  > n:
        continue
    
    for i in range(n-1):
        if fstr[:i+1] == cur[0][:i+1]:
            for j in range(i+1, n):
                if fstr[i+1:j+1] == cur[1][:j-i]:
                    if clen == 2:
                        flag = True
                        break
                    else:
                        for k in range(j+1, n):
                            if fstr[j+1:k+1] == cur[2][:k-j]:
                                flag = True
                                break
                            
                        if flag:
                            break
    
        if flag:
            res.append(cur)
            break
        
for i in range(len(res)-1):
    print(" ".join(res[i]), end=",")
    
print(" ".join(res[-1]))