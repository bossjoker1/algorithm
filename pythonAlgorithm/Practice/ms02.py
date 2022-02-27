def solution(A, B):
    n = len(A)
    la, lb = list(A), list(B)
    res = 0
    for i in range(n):
        for j in range(i+1, n+1):
            ta, tb = sorted(la[i:j]), sorted(lb[i:j])
            if ta == tb:
                res += 1

    return res
