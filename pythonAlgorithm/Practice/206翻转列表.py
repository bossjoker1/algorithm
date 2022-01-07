# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        p = None
        cur = head
        while cur != None:
            nn = cur.next
            cur.next = p
            p = cur
            cur = nn
        return p