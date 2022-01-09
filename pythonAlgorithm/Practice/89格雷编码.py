# 属于是数电题了
# 公式罢了，没什么意思
class Solution:
    def grayCode(self, n: int) -> List[int]:
        ans = [0]*(1<<n)
        for i in range(1<<n):
            ans[i] = (i >> 1) ^ i

        return ans