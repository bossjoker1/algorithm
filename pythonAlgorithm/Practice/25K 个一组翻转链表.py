# hard题

#1. 递归
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def reverse(self, head ,tail):
        pre = None
        while head != tail:
            next = head.next
            head.next = pre
            pre = head
            head = next
        return pre


    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        tail = head
        # 是否还有k个
        for i in range(k):
            if not tail:
                return head
            tail = tail.next
        
        nh = self.reverse(head, tail)
        head.next = self.reverseKGroup(tail, k)

        return nh
    
# 2.迭代法
# 官方题解这次很清楚
class Solution:
    # 翻转一个子链表，并且返回新的头与尾
    def reverse(self, head: ListNode, tail: ListNode):
        prev = None
        cur = head
        while prev != tail:
            nex = cur.next
            cur.next = prev
            prev = cur
            cur = nex
        return tail, head

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        hair = ListNode(0)
        hair.next = head
        pre = hair

        while head:
            tail = pre
            # 查看剩余部分长度是否大于等于 k
            for i in range(k):
                tail = tail.next
                if not tail:
                    return hair.next
            nex = tail.next
            head, tail = self.reverse(head, tail)
            # 把子链表重新接回原链表
            pre.next = head
            tail.next = nex
            pre = tail
            head = tail.next
        
        return hair.next
 

