# 水hard题
# 还可以自定义排序
# 重写__lt__方法，不太会

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        import heapq
        dummy = ListNode(0)
        p = dummy
        head = []
        for i in range(len(lists)):
            if lists[i] :
                heapq.heappush(head, (lists[i].val, i))
                lists[i] = lists[i].next
        while head:
            val, idx = heapq.heappop(head)
            p.next = ListNode(val)
            p = p.next
            if lists[idx]:
                heapq.heappush(head, (lists[idx].val, idx))
                lists[idx] = lists[idx].next
        return dummy.next


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:

        def __lt__(self, other):
            return self.val < other.val
        ListNode.__lt__ = __lt__
        
        import heapq
        heap = []
        dummy = ListNode(-1)
        p = dummy

        for l in lists:
            if l:
                heapq.heappush(heap, l)
        while heap:
            node = heapq.heappop(heap)
            p.next = ListNode(node.val)
            p = p.next
            if node.next:
                heapq.heappush(heap, node.next)
        
        return dummy.next