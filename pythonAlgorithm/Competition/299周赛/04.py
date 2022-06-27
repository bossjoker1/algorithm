# copy的 引入时间戳来确定树中父子节点的关系

class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        n = len(nums)
        g = [[] for _ in range(n)]
        for x, y in edges:
            g[x].append(y)
            g[y].append(x)

        xor, in_, out, clock = [0] * n, [0] * n, [0] * n, 0
        def dfs(x: int, fa: int) -> None:
            nonlocal clock
            clock += 1
            in_[x] = clock
            xor[x] = nums[x]
            for y in g[x]:
                if y != fa:
                    dfs(y, x)
                    xor[x] ^= xor[y]
            out[x] = clock
        dfs(0, -1)

        ans = inf
        for i in range(2, n):
            for j in range(1, i):
                if in_[i] < in_[j] <= out[i]:  # i 是 j 的祖先节点
                    x, y, z = xor[j], xor[i] ^ xor[j], xor[0] ^ xor[i]
                elif in_[j] < in_[i] <= out[j]:  # j 是 i 的祖先节点
                    x, y, z = xor[i], xor[i] ^ xor[j], xor[0] ^ xor[j]
                else:  # 删除的两条边分别属于两颗不相交的子树
                    x, y, z = xor[i], xor[j], xor[0] ^ xor[i] ^ xor[j]
                ans = min(ans, max(x, y, z) - min(x, y, z))
                # 注：把 min max 拆开，改为下面的注释，可以明显加快速度
                # mn = mx = x
                # if y < mn: mn = y 
                # elif y > mx: mx = y
                # if z < mn: mn = z 
                # elif z > mx: mx = z
                # if mx - mn < ans: ans = mx - mn
                if ans == 0: return 0  # 提前退出
        return ans

