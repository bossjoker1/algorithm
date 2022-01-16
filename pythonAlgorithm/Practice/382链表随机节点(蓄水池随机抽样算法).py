# 在不知道数据大小时，保证每个数据被选择的概率相等
# 思想：蓄水池算法
# 随机获取某个节点的复杂度为O(n)，因为每一次都要遍历一下

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.root = head

    def getRandom(self) -> int:
        node, ans, i = self.root, None, 0
        while node:
            # 1/k的概率选中
            if not randint(0, i):
                ans = node.val
            node, i = node.next, i+1

        return ans 


