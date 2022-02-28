# 题目意思看错了...
# 希望不会面试都进不去吧
from tkinter.tix import Tree


def solution(S):
    n = len(S)
    if n == 1:
        return 1
    res = 0
    flag = True
    for i in range(n):            
        if S[i] == "^" or S[i] == "v":
            res += 1
            flag = True
        if S[i] == "<":
            if i == 0 or flag:
                res += 1
        if S[i] == ">":
            if i == n-1:
                res+=1
            flag = False
    return res

s = "<<<><<<<^<<<>>v<<>"
print(solution(s))