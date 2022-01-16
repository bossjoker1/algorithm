# hard
# 字节技术营笔试压轴题
# 滑动窗口 + 队列 + 前缀和
# 指路 209
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        # 前缀和
        prefix = [0]
        for v in nums:
            prefix.append(prefix[-1]+v)

        # 双端队列维护前缀和的递增序列(索引，因为要知道步长)
        que = deque()
        res = math.inf
        for i in range(len(prefix)):
            while que and prefix[i] - prefix[que[0]] >= k:
                res = min(res, i - que[0])
                # 为什么要popleft? 对于不同的y2>y1，不会出现相同的x，使得y2-x为满足要求的最短选择
                que.popleft()

            while que and prefix[i] < prefix[que[-1]]:
                # 为什么要pop尾元素? 递增序列，只可能往后找
                que.pop()
            que.append(i)

        return res if res!=math.inf else -1

