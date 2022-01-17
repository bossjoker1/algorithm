# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        res = head
        pre = ListNode(0)
        pre.val = math.inf
        while head:
            if head.val != pre.val:
                pre = head
                head = head.next
                continue

            while head and head.val == pre.val:
                head = head.next
            pre.next = head
            pre = head
        return res
                
