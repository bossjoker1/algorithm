class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        res, row, col = [], {}, {}
        m, n = len(matrix), len(matrix[0])

        for i in range(m):
            k, minv = -1, 100005
            for j in range(n):
                if matrix[i][j] < minv:
                    k = j
                    minv = matrix[i][j]
            row[i] = k

        for i in range(n):
            k, maxv = -1, -1
            for j in range(m):
                if matrix[j][i] > maxv:
                    k = j
                    maxv = matrix[j][i]
            col[i] = k

        
        for i in range(m):
            if col[row[i]] == i:
                res.append(matrix[i][row[i]])

        return res
