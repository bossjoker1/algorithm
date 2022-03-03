# z字形，以矩形的右上角为基准进行搜索
# 如果target比它小，则说明当前矩形列都比target大
# 如果比它大，则说明当前列都会比target小
# 矩形逐渐缩小，直至找不到或者中间返回
# 一次淘汰一行或一列

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        x, y = 0, n - 1
        while x < m and y >= 0:
            if matrix[x][y] == target:
                return True
            if matrix[x][y] > target:
                y -= 1
            else:
                x += 1
        return False


# 没有用到从上至下的条件
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
    
        def BinarySearh(line :List[int]) -> bool:
            l, r = 0, n
            while l < r:
                mid = (l + r) >> 1
                if line[mid] == target:
                    return True
                elif line[mid] < target:
                    l = mid + 1
                else:
                    r = mid
            return False

        for line in matrix:
            if BinarySearh(line):
                return True

        return False

# 调库
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            idx = bisect.bisect_left(row, target)
            if idx < len(row) and row[idx] == target:
                return True
        return False