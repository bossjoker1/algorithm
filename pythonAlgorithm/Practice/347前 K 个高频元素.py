# 要求时间复杂度小于O(nlogn)
# O(n*logk)解法

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = []
        cnt = {}
        for item in nums:
            c = cnt.get(item, 0)
            cnt[item] = c + 1
        for key, val in cnt.items():
            if len(res) < k:
                heapq.heappush(res, (val, key))
            elif val > res[0][0]:
                heapq.heappop(res)
                heapq.heappush(res, (val, key)) 
        ans = []
        for i in range(len(res)):
            ans.append(res[i][1])
        return ans