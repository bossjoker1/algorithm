# 数学?
class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        # 艹，逆向思维确实nb
        if tx < sx or ty < sy:return False

        while tx and ty:
            if tx == sx and ty == sy:
                return True
            # 只能较大的值减小
            if tx > ty:
                # (x, x+y) or (x+y, x) => (x, y)
                tx -= max((tx - sx) // ty, 1) * ty
            else:
                ty -= max((ty - sy) // tx, 1) * tx

        return False