# 注意两条链表遍历完后还加出来的进位
# 需要额外补一个点

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        h1, h2 = l1, l2
        b = 0
        head = ListNode(0)
        pre = head
        while h1 and h2:
            node = ListNode(0)
            node.val = (h1.val + h2.val + b) % 10
            b = (h1.val + h2.val + b) // 10
            pre.next = node
            pre = node
            h1, h2 = h1.next, h2.next

        if h1:
            while h1:
                node = ListNode(0)
                node.val = (h1.val + b) % 10
                b = (h1.val + b) // 10
                pre.next = node
                pre = node
                h1 = h1.next
        else:
            while h2:
                node = ListNode(0)
                node.val = (h2.val + b) % 10
                b = (h2.val + b) // 10
                pre.next = node
                pre = node
                h2 = h2.next

        if b:
            node = ListNode(0)
            node.val = b
            pre.next = node

        return head.next

# 精简算法，但实际上每次都判断，耗时更长
# 只是代码量少了而已
class Solution:
    def addTwoNumbers(self, h1: ListNode, h2: ListNode) -> ListNode:
        b = 0
        head = ListNode(0)
        pre = head
        while h1 or h2 or b:
            val1 = h1.val if h1 else 0
            val2 = h2.val if h2 else 0
            s = val1 + val2 + b
            node = ListNode(0)
            node.val = s % 10
            b = s // 10
            pre.next = node
            pre = node
            
            if h1: h1 = h1.next
            if h2: h2 = h2.next

        return head.next