# n<=15，状态压缩？
class Solution:
    def countArrangement(self, n: int) -> int:
        # state中的位为1表示该数字被选择了
        # dp[state] 表示state下前i个能满足条件的个数
            # 优化获取state中1的个数
        def getCnt(x:int) ->int:
            ans = 0
            while x:
                x -= x & -x # lowbit
                ans+=1
            return ans
        
        mask = 1 << n
        dp = [0] * mask
        dp[0] = 1
        for state in range(1, mask):
            cnt = getCnt(state)
            for i in range(n):
                if (state >> i) & 1 == 0: continue
                if (i+1) % cnt  and cnt % (i+1) : continue
                dp[state] += dp[state & (~(1<<i))]
        return dp[mask - 1]


# 回溯

class Solution:
    cnt = 0
    def countArrangement(self, n: int) -> int:
        visited = [0] * (n+1)
        def backTrack(num:int, n:int, visited: List[int]):
            if num == n:
                self.cnt += 1
                return

            for i in range(1, n+1):
                if not visited[i]:
                    visited[i] = 1
                    if i % (num + 1) == 0 or (num + 1) % i == 0:
                        backTrack(num + 1, n, visited)
                    visited[i] = 0


        backTrack(0, n, visited)

        return self.cnt