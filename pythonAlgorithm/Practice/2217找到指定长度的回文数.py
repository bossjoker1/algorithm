# 数学题
class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        n = len(queries)
        d = intLength // 2 + intLength % 2
        base = 10**(d-1) if d != 1 else 1
        res = []
        for item in queries:
            pre = base + item - 1
            if pre >= 10 ** d:
                res.append(-1)
            else:
                if intLength % 2 == 0:
                    res.append( int( str(pre) + str(pre)[::-1] ))
                else:
                    res.append( int( str(pre) + str(pre)[:-1][::-1] ))

        return res
    
    
# dl的写法
class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        ans = [-1] * len(queries)
        base = 10 ** ((intLength - 1) // 2)
        for i, q in enumerate(queries):
            if q <= 9 * base:
                s = str(base + q - 1)  # 回文数左半部分
                print(s)
                s += s[-2::-1] if intLength % 2 else s[::-1]
                ans[i] = int(s)
        return ans
