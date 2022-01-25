# 归并，递归，空间复杂度为o(logn),即栈的深度
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 退出条件
        if not head or not head.next:
            return head

        # 快慢指针找中点
        slow, fast = head, head.next

        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        # 得到右半边的链头
        # 切断左半边的链尾
        mid, slow.next  = slow.next, None

        # 递归
        left, right = self.sortList(head), self.sortList(mid)

        # 合并
        res = ListNode(0)
        temp = res
        while left and right:
            if left.val < right.val:
                temp.next, left = left, left.next
            else:
                temp.next, right = right, right.next
            temp = temp.next
        temp.next = left if left else right

        return res.next

# 迭代法将空间复杂度降为O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        h, length, d = head, 0, 1
        while h:
            h, length = h.next, length + 1

        hair = ListNode(0)
        hair.next = head
        
        # 合并长度为1, 2, 4, ...
        # 每次从头开始
        while d < length:
            pre, h = hair, hair.next
            while h:
                h1, i = h, d
                while i and h:
                    h, i = h.next, i-1
                # 说明没有h2了
                if i: break
                h2, i = h, d
                while i and h:
                    h, i = h.next, i-1
                # 各段的长度
                c1, c2 = d, d-i

                # 开始合并
                while c1 and c2:
                    if h1.val < h2.val:
                        pre.next, h1, c1 = h1, h1.next, c1-1
                    else:
                        pre.next, h2, c2 = h2, h2.next, c2-1
                    pre = pre.next
                pre.next = h1 if c1 else h2

                while c1 > 0 or c2 > 0:
                    pre, c1, c2 = pre.next, c1-1, c2-1
                # 链接下一个合并单元                
                pre.next = h

            d *= 2
        return hair.next

