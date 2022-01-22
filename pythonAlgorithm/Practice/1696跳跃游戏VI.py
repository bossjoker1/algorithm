# 限制k步
# 得分累积最多
# dp思想 + 堆维护最大值

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res = nums[0]
        heap = []
        heapq.heappush(heap, (-nums[0], 0))
        for i in range(1, n):
            if heap:
                while i - heap[0][1] > k:
                    heapq.heappop(heap)
                val = -heap[0][0]
                res = nums[i] + val
                heapq.heappush(heap, (-res, i))
        return res
    
    
# 方法二：单调队列或者叫滑动窗口
# 维护 索引递增（所以也叫窗口），值递减的队列

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        q = deque()
        q.append([nums[0], 0])
        ans = nums[0]

        for i in range(1, n):
            while i - q[0][1] > k:
                q.popleft()

            ans = q[0][0] + nums[i]

            while q and ans > q[len(q)-1][0]:
                q.pop()

            q.append([ans, i])

        return ans

