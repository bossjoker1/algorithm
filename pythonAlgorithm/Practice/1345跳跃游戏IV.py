# hard 
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)
        mp = defaultdict(list)
        # 得到每个值的坐标索引
        for i in range(n):
            mp[arr[i]].append(i)

        dist = [inf]*n

        q = deque([0])

        dist[0] = 0

        while len(q) > 0:
            t = q.popleft()
            step = dist[t]
            if t == n-1:
                return step
            
            for idx in mp[arr[t]]:
                if dist[idx] == inf:
                    q.append(idx)
                    dist[idx] = step + 1

            # 清除，因为已经全部加入到队列中了
            # 不可能出现跳到前面的跟自己值相同的位置
            mp[arr[t]].clear()

            if dist[t+1] == inf:
                q.append(t+1)
                dist[t+1] = step + 1

            if t and dist[t-1] == inf:
                q.append(t-1)
                dist[t-1] = step + 1

        return -1 
