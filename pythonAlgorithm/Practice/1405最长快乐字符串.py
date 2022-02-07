class Solution:
    # 先选择最多的，再选择次优的，少的要用来隔开字母
    
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        maxHeap = []
        heapq.heapify(maxHeap)
        if a > 0:   heapq.heappush(maxHeap, (-a, 'a'))
        if b > 0:   heapq.heappush(maxHeap, (-b, 'b'))
        if c > 0:   heapq.heappush(maxHeap, (-c, 'c'))
    
        res = ""
        while maxHeap:
            f, x = heapq.heappop(maxHeap)
            f *= (-1)

            if len(res) >= 2 and res[-2] == res[-1] == x:
                #----不能构成3连。所以选取下一个
                if len(maxHeap) == 0:
                    break
                f2, y = heapq.heappop(maxHeap)
                f2 *= (-1)
                res += y
                f2 -= 1
                if f2 != 0:
                    heapq.heappush(maxHeap, (-f2, y))
                heapq.heappush(maxHeap, (-f, x))
            else:
                res += x
                f -= 1
                if f != 0:
                    heapq.heappush(maxHeap, (-f, x))
        
        return res