import sys

def solution(A):
    n = len(A)
    l, r = 1, 3
    minl = sys.maxsize
    res = sys.maxsize
    while r < n-1:
        minl = min(minl, A[l])
        res = min(res, minl + A[r])
        r += 1
        l += 1

    return res