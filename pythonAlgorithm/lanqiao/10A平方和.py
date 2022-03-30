N = 2019

def check(x:int)->bool:
    while x:
        if x%10 in [2, 0, 1, 9]:
            return True
        x //= 10
        
    return False

res = 0
for i in range(1, N+1):
    if check(i):
        res += i*i

# 2658417853   
print(res)