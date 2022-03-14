# 字节笔试题，麻了
# 步数        能到达的位置
# 1:          1
# 2:          3, 1
# 3:          6, 4, 2, 0
# 4:          10, 8, 6, 4, 0
# 5:          15, 13, 11, 9, 7, 5, 3, 1
# 得出如果能在第N步到达，则target <= max(n)，且同奇偶

class Solution:
    def reachNumber(self, target: int) -> int:
        target = abs(target)

        cur, step = 0, 0

        while cur < target or (target + cur) % 2 != 0:
            step += 1
            cur += step

        return step