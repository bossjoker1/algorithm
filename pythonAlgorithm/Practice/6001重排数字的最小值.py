# 可以跟这个值一样
# 指路31"下一个排列"，感觉那个更复杂点

class Solution:
    def smallestNumber(self, num: int) -> int:

        def cal(bit:List[int]) -> int:
            res, n = 0, len(bit)
            for i in range(n-1):
                res += bit[i]
                res *= 10
            res += bit[n-1]
            return res

        if num == 0:
            return 0

        bit, res = [], 0
        temp = abs(num)
        while temp:
            bit.append(temp % 10)
            temp //= 10
        if num > 0:
            bit.sort()
            if bit[0] == 0:
                for i in range(len(bit)):
                    if bit[i] > 0:
                        bit[0], bit[i] = bit[i], bit[0]
                        break
            res = cal(bit)
        else:
            bit.sort(reverse=True)
            res = -1 * cal(bit)

        return res
