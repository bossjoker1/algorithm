class Solution:
    def calPoints(self, ops: List[str]) -> int:
        res = []
        for i in range(len(ops)):
            if ops[i] == '+':
                res.append(res[-1]+res[-2])
            elif ops[i] == 'D':
                res.append(res[-1]*2)
            elif ops[i] == 'C':
                res.pop()
            else:
                res.append(int(ops[i]))

        return sum(res)
