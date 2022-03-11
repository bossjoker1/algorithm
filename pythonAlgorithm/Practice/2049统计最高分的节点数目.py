class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        n = len(parents)
        g = defaultdict(list)
        for i in range(1, n):
            g[parents[i]].append(i)
        nums = [1] * n

        def dfs(root:int) -> int:
            if root not in g:
                return 1
            for item in g[root]:
                nums[root] += dfs(item)
            return nums[root]
        dfs(0)
        maxn, cnt = -1, 0
        for i in range(n):
            res = 1
            if parents[i] == -1:
                res *= 1
            else:
                res *= nums[0] - nums[i]
            for item in g[i]:
                res *= nums[item]
            if res == maxn:
                cnt += 1
            elif res > maxn:
                maxn = res
                cnt = 1

        return cnt
