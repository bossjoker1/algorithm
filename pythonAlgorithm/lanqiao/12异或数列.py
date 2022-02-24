# 不知道哪个sb样例没过，思路都是一样的
# c++能过 艹
T = int(input())

for c in range(T):
    nums, s = [0] * 21, 0
    X = list(map(int, input().split()))
    for i in range(1, len(X)):
        a = X[i]
        s ^= a
        cnt = 1
        while a :
            if a & 1:
                nums[cnt]+=1
            cnt += 1
            a >>= 1
                
    if s == 0:
        print("0")
    else:
        for i in range(20, 0, -1):
            if nums[i] == 1:
                print("1")
                break
            elif nums[i] % 2 == 1:
                if X[0] % 2 == 1:
                    print("1")
                    break
                else:
                    print("-1")
                    break