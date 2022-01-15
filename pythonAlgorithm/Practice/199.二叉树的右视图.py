# 层次遍历
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root: return []
        res = []
        q = deque([root])
        cnt = len(q)
        while q:
            for i in range(1, cnt):
                temp = q.popleft()
                if temp.left: 
                    q.append(temp.left)
                if temp.right:
                    q.append(temp.right)
            cur = q.popleft()
            res.append(cur.val)
            if cur.left:
                q.append(cur.left)
            if cur.right:
                q.append(cur.right)
            cnt = len(q)
        return res
