# 按位数进行分类
# 找到n对应那个区间以及base
# 然后得到其对应的偏移
class Solution:
    def findNthDigit(self, n: int) -> int:
        post = 10
        base = 1
        temp = 0
        while n > post:
            temp = post
            post += 9*(10**(base)) * (base+1)
            base += 1

        # print(temp, post, base)

        curr =  (n - temp) // base

        idx = curr + (10**(base-1) if base > 1 else 0)

        # print(idx)

        return int(str(idx)[(n - temp)%base])
