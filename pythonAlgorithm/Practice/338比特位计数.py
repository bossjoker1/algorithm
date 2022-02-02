# 简单题，但学到许多

# x & (x-1)
# O(nlogn)
class Solution:
    def countBits(self, n: int) -> List[int]:
        def countOnes(x:int) -> int:
            cnt = 0
            while x > 0:
                # 将X中最后一个1置为0
                x = x & (x-1)
                cnt += 1

            return cnt

        res = [countOnes(i) for i in range(n+1)]

        return res
    
# 结合动态规划的三种方法，思想同方法一，利用其递推关系
class Solution:
    def countBits(self, n: int) -> List[int]:
        bits = [0]
        for i in range(1, n + 1):
            bits.append(bits[i & (i - 1)] + 1)
        return bits
    
# 最高有效位，得到不大于x的2的整数幂z，则 x-z的数与x只相差最高位的一个1
class Solution:
    def countBits(self, n: int) -> List[int]:
        bits = [0]
        highBit = 0
        for i in range(1, n + 1):
            if i & (i - 1) == 0:
                highBit = i
            bits.append(bits[i - highBit] + 1)
        return bits

# 最低有效位，由位运算可知，右移相当于去掉最右边的1或0
class Solution:
    def countBits(self, n: int) -> List[int]:
        bits = [0]
        for i in range(1, n + 1):
            bits.append(bits[i >> 1] + (i & 1))
        return bits


