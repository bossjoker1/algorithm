class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        n = len(colors)
        if n < 3:
            return False
        cntA, cntB = 0, 0
        temp, flag = 1, colors[0]
        for i in range(1, n):
            # print("cntA : %d, cntB : %d, flag : %s, temp : %d"%(cntA, cntB, flag, temp))
            if colors[i] == flag:
                temp += 1
            if  colors[i] != flag or i == n-1:
                if temp >= 3:
                    if flag == 'A':
                        cntA += temp - 2
                    else:
                        cntB += temp - 2
                flag = colors[i]
                temp = 1
        if cntA < cntB + 1:
            return False
        else:
            return True
