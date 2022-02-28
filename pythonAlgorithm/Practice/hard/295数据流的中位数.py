# 用两个堆实现，只能说没做过的很难想到
class MedianFinder:

    def __init__(self):
        self.left, self.right = [], []

    def addNum(self, num: int) -> None:
        s1, s2  = len(self.left), len(self.right)
        if s1 == s2:
            if not self.right or num <= self.right[0]:
                heapq.heappush(self.left, -num)
            else:
                heapq.heappush(self.left, -heapq.heappop(self.right))
                heapq.heappush(self.right, num)
        else:
            if num >= -self.left[0]:
                heapq.heappush(self.right, num)
            else:
                heapq.heappush(self.right, -heapq.heappop(self.left))
                heapq.heappush(self.left, -num)
            
    def findMedian(self) -> float:
        if len(self.left) == len(self.right):
            return (-self.left[0] + self.right[0]) / 2
        else:
            return -self.left[0] 

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()