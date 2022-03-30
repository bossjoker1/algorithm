class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        available = list(range(k))
        busy = [] 
        res = [0] * k
        for i, a in enumerate(arrival):
            # print("available : ", available)
            # print("busy: ", busy)
            while busy and busy[0][0] <= a:
                _, x = heapq.heappop(busy)
                heapq.heappush(available, i + (x - i) % k)

            if available: 
                j = heapq.heappop(available) % k
                heapq.heappush(busy, (a+load[i], j))
                res[j] += 1

        max_reqs = max(res)
        return [i for i in range(k) if res[i] == max_reqs]
