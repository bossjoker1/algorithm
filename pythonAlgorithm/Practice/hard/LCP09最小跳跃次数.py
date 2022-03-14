# hard
# bfs + 剪枝

class Solution:
    def minJump(self, jump: List[int]) -> int:
        n = len(jump)
        step = 0
        # mx表示其左边弹簧都已经访问过了
        # 0为初始访问，所以从1开始
        mx = 1
        q = deque([0])
        while q:
            # 每一次循环表示在step下能到达的弹簧
            tempSize = len(q)
            for i in range(tempSize):
                cur = q.popleft()

                if cur + jump[cur] >= n:
                    return step + 1

                if cur + jump[cur] >= mx:
                    q.append(cur + jump[cur])

                # 左边从未访问过的弹簧开始遍历，剪枝
                # 否则会TLE
                for j in range(mx, cur):
                    q.append(j)
                
                # 此时cur左边的都已经访问过了
                # 更新mx
                mx = max(mx, cur + 1)

            step += 1

        return step


# dp 从后往前

class Solution:
    def minJump(self, jump: List[int]) -> int:
        dp = [0] * len(jump)
        for i in range(len(jump)-1,-1,-1):
            if i + jump[i] >= len(jump):
                dp[i] = 1
            else:
                dp[i] = 1 + dp[i + jump[i]]
            for j in range(i+1,len(jump)):
                # 此时对于i后面的j出现了两种选择：向右跳还是向左跳
                if dp[j] <= dp[i]: # 当出现这种情况，下标比j还大的后面的就可以选择从j跳了，因此不用再从i跳
                    break
            else:
                # 出现更优解为：先向左跳到i，再继续跳
                    dp[j] = dp[i] + 1
        return dp[0]
