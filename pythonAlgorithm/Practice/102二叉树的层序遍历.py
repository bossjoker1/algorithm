# 用到deque队列的基本方法

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root:
            return res
        q = collections.deque()
        q.append(root)
        while q:
            l = len(q)
            ans = []
            for i in range(l):
                temp = q.popleft()
                ans.append(temp.val)
                if temp.left:
                    q.append(temp.left)
                if temp.right:
                    q.append(temp.right)
            res.append(ans)
        return res
