# hard...
# 排列组合，忽略干扰的植物

class Solution:
    def numberOfWays(self, corridor: str) -> int:
        ans, cnt, pre = 1, 0, 0
        for i, s in enumerate(corridor):
            if s == 'S':
                cnt += 1
                # 3, 5, 7座位只需在到最左边的座位之间插入一个屏风即可
                if cnt >= 3 and cnt % 2 == 1:
                    ans = ans* (i- pre) % 1000000007
                pre = i

        return ans if cnt and cnt % 2 == 0 else 0