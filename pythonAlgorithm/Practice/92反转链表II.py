# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        hair = ListNode(0)
        hair.next = head
        pre = hair
        i = 1
        while i < left:
            pre = head
            head = head.next
            i+=1
        
        prev = None
        cur =  head
        while i <= right:
            nex = cur.next
            cur.next = prev
            prev = cur
            cur = nex
            i+=1
        # 此时cur指向最右边
        pre.next = prev
        head.next = cur

        return hair.next
        

        
