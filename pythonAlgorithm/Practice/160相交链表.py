# 无脑set
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        seen = set()
        while headA:
            seen.add(headA)
            headA = headA.next

        while headB:
            if headB in seen:
                return headB
            headB = headB.next
        return None

# 重定位到另一个链表的头，消除了距离差，第二次遍历即可相遇
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA == None or headB == None:
            return None
        A, B = headA, headB
        while A != B:
            A = headB if A == None else A.next
            B = headA if B == None else B.next
        return A
