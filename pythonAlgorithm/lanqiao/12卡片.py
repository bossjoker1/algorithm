cnt = [2021] * 10

i = 1

def sub(i:int) -> bool: 
    while i:
        temp = i % 10
        if cnt[temp] > 0:
            cnt[temp] -= 1
        else:
            return False
        i //= 10
    return True

while True:
    if not sub(i):
        # 3181
        print(i-1)
        break
    i += 1

        