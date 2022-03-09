# 差分数组
class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        n = len(nums)
        diff = [0] * (n+1)

        for i in range(n):
            a, b = (i - n + 1 + n) % n, (i - nums[i] + n) % n
            if a <= b:
                diff[a] += 1
                diff[b+1] -= 1
            else:
                diff[0] += 1
                diff[b+1] -= 1
                diff[a] += 1
                diff[n] -= 1

        score, idx, maxScore = 0, -1, 0

        for i in range(n+1):
            score += diff[i]
            if score > maxScore:
                idx = i
                maxScore = score

        return idx

