# 计算一个字符到其左右两边相同字符的距离
# tnnd原来它是第3题
s = input()
sum = 0
for i in range(len(s)):
    loc = i - 1
    while s[loc] != s[i] and loc >= 0:
        loc -= 1
    prenum = i - loc
    loc = i + 1
    while loc < len(s) and s[loc] != s[i]:
        loc += 1
    posnum = loc - i
    sum += posnum * prenum
print(sum)


# import collections
# s = input()
# res = 0
# for i in range(len(s)):
#     for j in range(i + 1, len(s) + 1):
#         dic = collections.Counter(s[i:j])
#         # print(s[i:j], dic)
#         for key, value in dic.items():
#             if value == 1: res += 1
# print(res)


# s = input()

# n = len(s)

# prefix = [[0] * (n+1) for _ in range(26)] 

# for i in range(1, n+1):
#     for j in range(26):
#         prefix[j][i] += prefix[j][i-1] + 1 if (ord(s[i-1]) - ord('a') == j) else prefix[j][i-1]

# res = 0
# for d in range(1, n+1):
#     cur = 0
#     cnt = 0
#     while cur + d <= n:
#         for j in range(26):
#            if prefix[j][cur + d] - prefix[j][cur] == 1:
#                res += 1
#                cnt += 1 
#         cur += 1

# print(res)