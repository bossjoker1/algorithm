# hard，之前做了一次超时没过

class Solution:
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        
        # 是否满足要求
        def check(x, y, s):
            for i in range(9):
                # 行列不重复
                if board[i][y] == s or board[x][i] == s:
                    return False
            # 3*3格子内不能重复
            for i in [0, 1, 2]:
                for j in [0, 1, 2]:
                    if board[x//3*3+i][y//3*3+j] == s:
                        return False
            return True
        
        def backTrack(cur):
            # 填完了且满足要求
            if cur == 81:
                print(board)
                return True
            x, y = cur // 9, cur % 9
            # 遇到要填的，开始递归
            if board[x][y] != '.':
                return backTrack(cur + 1)
            # 尝试所有数字
            for i in range(1, 10):
                s = str(i)
                if check(x, y, s):
                    board[x][y] = s
                    if backTrack(cur + 1):
                        return True
                    board[x][y] = '.'
            return False
        
        backTrack(0)