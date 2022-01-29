class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        res.append([1])
        for i in range(2, numRows+1):
            temp = []
            for j in range(i):
                if j == 0 or j == i-1 :
                    temp.append(1)
                else:
                    temp.append(res[-1][j-1] + res[-1][j])
            res.append(temp)

        return res