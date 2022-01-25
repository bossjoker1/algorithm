# O(n2)
# 维护有序部分的尾节点
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head:
            return head

        hair = ListNode(0)
        hair.next = head

        lartSorted, curr = head, head.next

        while curr:

            if lartSorted.val <= curr.val:
                lartSorted = lartSorted.next
            else:
                pre = hair
                while pre.next.val <= curr.val:
                    pre = pre.next
                lartSorted.next = curr.next
                curr.next = pre.next
                pre.next = curr

            curr = lartSorted.next

        return hair.next