# 前缀和
class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        dp = [0] * n
        pre_sum = [0] * (n+1)
        dp[0] = pre_sum[1] = 1
        for i in range(1, n):
            if s[i] == "0":
                l, r = max(0, i - maxJump), min(n-1, i - minJump)
                if r >= 0 and pre_sum[r+1] - pre_sum[max(l, 0)] > 0:
                    dp[i] = 1
            pre_sum[i+1] = pre_sum[i] + dp[i]
        return dp[n-1] == 1


# bfs + 右指针剪枝

class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        last, n = 0, len(s)
        if s[-1] == '1': return False
        q = deque([0])

        while q:
            t = q.popleft()
            for i in range(max(last+1, t + minJump), min(n, t+maxJump+1)):
                last = i
                if s[i] != '0': continue
                q.append(i)
                if i == n-1:
                    return True

        return False