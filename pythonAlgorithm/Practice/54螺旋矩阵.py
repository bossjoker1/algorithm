# 关键步骤：取模防止越界
# 交换di,dj：拐弯
# 0, 1 :向右
# 1, 0 :向下
# 0, -1:向左
# -1, 0:向上
# 遍历过的值赋为1，发现是找过的值则拐弯
# nb!
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # 一开始向右找
        m, n = len(matrix), len(matrix[0])
        r, i, j, di, dj = [], 0, 0, 0, 1
        if matrix != []:
            for _ in range(len(matrix) * len(matrix[0])):
                r.append(matrix[i][j])
                matrix[i][j] = 0
                if matrix[(i + di) % m][(j + dj) % n] == 0:
                    di, dj = dj, -di
                i += di
                j += dj
        return r