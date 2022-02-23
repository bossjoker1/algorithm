# 我的解法，还行
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp, pre = head.next, head.next
        while temp:
            if temp.val == 0:
                pre.next = temp.next
                pre = temp.next
            else:
                if temp.next:
                    pre.val += temp.next.val
            temp = temp.next
        return head.next
    
# dl的原地修改，nb!

class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ans, temp = head, head.next
        s = 0
        while temp:
            if temp.val != 0:
                s += temp.val
            else:
                ans.next.val = s
                ans = ans.next
                s = 0
            temp = temp.next
        ans.next = None

        return head.next