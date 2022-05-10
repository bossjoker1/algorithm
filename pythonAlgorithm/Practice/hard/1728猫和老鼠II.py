# 完全不会...
DIRS = (0, 1), (1, 0), (0, -1), (-1, 0)
class Solution:
    def canMouseWin(self, grid: List[str], catJump: int, mouseJump: int) -> bool:
        mm, nn = len(grid), len(grid[0])
        for x in range(mm):
            for y in range(nn):
                match grid[x][y]:
                    case 'C':
                        cat = x, y
                    case 'F':
                        food = x, y
                    case 'M':
                        mouse = x, y

        @lru_cache(None)
        def dfs(m, c, i):
            """
            极大极小博弈，
            老鼠尽量找自己获胜的，其次接受平局
            猫尽量找自己获胜的，其次接受平局

            :param m: 老鼠的位置
            :param c: 猫的位置
            :param i: 回合
            """
            if m == c or c == food or i > 128:
                return False
            if m == food:
                return True
            is_cat = False
            # 猫回合
            if i % 2:
                pos, jump = c, catJump
                is_cat = True
            else:
                pos, jump = m, mouseJump
            for dx, dy in DIRS:
                for jp in range(jump + 1):
                    nx, ny = pos[0] + dx * jp, pos[1] + dy * jp
                    if nx < 0 or ny < 0 or nx >= mm or ny >= nn or grid[nx][ny] == '#':
                        break
                    if not is_cat and dfs((nx, ny), c, i + 1):
                        return True
                    elif is_cat and not dfs(m, (nx, ny), i + 1):
                        return False
            return is_cat
        
        return dfs(mouse, cat, 0)


