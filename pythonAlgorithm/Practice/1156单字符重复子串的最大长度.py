# 枚举26个字母的子串排列，隔一个的可以直接相连
class Solution:
    def maxRepOpt1(self, text: str) -> int:
        n = len(text)
        # idxs = [[] for _ in range(26)]
        # 求a~z的连续子串的位置
        maxn = 1
        for k in range(26):
            start = -1
            cnt = 0
            temp = []
            for i in range(n):
                if text[i] == chr(97+k):
                    if start == -1:
                        start = i
                    cnt += 1
                if (text[i] != chr(97+k) or i == n-1) and start != -1:
                    temp.append((start, cnt))
                    start = -1
                    cnt = 0
            m = len(temp)

            # print(temp)
            
            if m == 0:
                continue
            elif m == 1:
                maxn = max(maxn, temp[0][1])
            elif m == 2:
                if temp[0][0] + temp[0][1] + 1 == temp[1][0]:
                    maxn = max(maxn, temp[0][1] + temp[1][1])
                else:
                    maxn = max(maxn, max(temp[0][1], temp[1][1])+1)

            else:
                ps, pc = temp[0][0], temp[0][1]
                tmaxn = pc + 1
                for j in range(1, m):
                    cs, cc = temp[j][0], temp[j][1]
                    if cs == ps + pc + 1:
                        tmaxn = max(tmaxn, pc + cc + 1)
                    else:
                        tmaxn = max(tmaxn, cc + 1)
                    ps, pc = cs, cc
                maxn = max(maxn, tmaxn)

        return maxn