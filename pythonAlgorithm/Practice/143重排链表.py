# 快慢指针找到中点，中点及以后逆序
# 依次插入到中点前半部分

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # 翻转函数
        def reverse(temp:ListNode) ->ListNode:
            pre = None
            cur = temp
            while cur:
                next = cur.next
                cur.next = pre
                pre = cur
                cur = next
            return pre

        # 快慢指针找中点

        if not head or not (head.next):
            return
        slow, fast = head, head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next

        # 划分为两部分
        head1, head2 = head, reverse(slow)

        # 接入
        while head1 != head2 and head1.next != head2:
            next1, next2 = head1.next, head2.next
            head1.next, head2.next = head2, next1
            head1, head2 = next1, next2
