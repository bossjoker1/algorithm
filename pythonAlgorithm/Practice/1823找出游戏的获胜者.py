class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        q = [i for i in range(1, n+1)]
        cur, tn = 0, n
        while tn > 1:
            cur = (cur + k - 1) % tn
            q.pop(cur)
            tn -= 1

        return q[0]