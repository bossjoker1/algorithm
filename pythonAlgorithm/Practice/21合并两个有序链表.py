# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        new_head = ListNode()
        tp = new_head
        while l1 and l2:
            if l1.val < l2.val:
                new_head.next = l1
                new_head = new_head.next
                l1 = l1.next
            else :
                new_head.next = l2
                new_head = new_head.next
                l2 = l2.next
        if l1 or l2:
            new_head.next = l1 or l2
        return tp.next