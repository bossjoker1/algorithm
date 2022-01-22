# bfs

class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        dp = [0]*n
        q = deque([start])

        while q:
            t = q.popleft()
            if arr[t] == 0:
                return True
            dp[t] = 1

            if t - arr[t] >= 0 and not dp[t - arr[t]]:
                q.append(t - arr[t])

            if t + arr[t] < n and not dp[t + arr[t]]:
                q.append(t + arr[t])

        return False
