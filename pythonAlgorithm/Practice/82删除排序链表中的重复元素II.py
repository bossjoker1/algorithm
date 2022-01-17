# 82需要将有重复的元素连同其本身一并删除，所以还需要前前指针
# leetcode第200道题！！！
# 指路83


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        hair = ListNode(0)
        hair.val = math.inf
        hair.next = head
        ppre, pre = hair, hair

        while head:
            if head.val != pre.val:
                ppre = pre
                pre = head
                head = head.next

                continue

            while head and head.val == pre.val:
                head = head.next
            pre = ppre
            ppre.next = head

        return hair.next
            


