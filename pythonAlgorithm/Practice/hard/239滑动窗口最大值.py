# hard

# 优先队列
# 需要添加索引，以便查看最大值是否处于窗口内，否则就及时pop掉
# 时间复杂度较高 O(nlogn) 
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        # 注意 Python 默认的优先队列是小根堆
        q = [(-nums[i], i) for i in range(k)]
        heapq.heapify(q)

        ans = [-q[0][0]]
        for i in range(k, n):
            heapq.heappush(q, (-nums[i], i))
            while q[0][1] <= i - k:
                heapq.heappop(q)
            ans.append(-q[0][0])
        
        return ans
    
# 用deque维护单调队列 这种思想和数据结构要掌握！！！
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        q = deque()
        for i in range(k):
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)

        ans = []
        ans.append(nums[q[0]])
        for i in range(k, n):
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
            # 不在窗口内
            while q[0] <= i-k:
                q.popleft()

            ans.append(nums[q[0]])
        return ans



        
