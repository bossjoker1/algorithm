# nb解法
# 利用递归的“栈”特性，实现倒叙
class Solution:
    cur = 0
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if not head:
            return None
        head.next = self.removeNthFromEnd(head.next, n)
        self.cur += 1
        if n == self.cur:
            return head.next
        return head
            
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        hair = ListNode(0)
        hair.next = head
        cnt = 0
        tmp = head
        while tmp:
            cnt += 1
            tmp = tmp.next

        seq = cnt - n
        pre = hair
        for i in range(seq):
            pre = pre.next

        pre.next = pre.next.next

        return hair.next
            
        

        
