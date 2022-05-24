# 还算精简的递归
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root:
            return True

        return (((root.val == root.left.val) if root.left else True) and self.isUnivalTree(root.left)) and (((root.val == root.right.val) if root.right else True) and self.isUnivalTree(root.right))
