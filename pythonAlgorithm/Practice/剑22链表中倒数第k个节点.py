# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


# 快慢指针
# 快指针多走k步

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        slow, fast = head, head
        while fast and k > 0:
            fast = fast.next
            k -= 1

        while fast:
            fast = fast.next
            slow = slow.next

        return slow


# 一般解法
class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        size = 0
        temp = head
        while temp:
            size+=1
            temp = temp.next
        size = size - k
        cur = head
        for i in range(size):
            cur = cur.next

        return cur