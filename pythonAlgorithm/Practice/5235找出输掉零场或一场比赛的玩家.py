# 图？
# hash表√
class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        ans = [[], []]
        winall = defaultdict(int)
        loseOne = defaultdict(int)

        for w, l in matches:
            if winall[l] != -1:
                winall[l] = -1
            loseOne[l] += 1
            if winall[w] == 0:
                winall[w] = 1

        for k, v in winall.items():
            if v != -1:
                ans[0].append(k)
        for k, v in loseOne.items():
            if v == 1:
                ans[1].append(k)

        ans[0].sort()
        ans[1].sort()

        return ans        