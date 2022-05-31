# 递归
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        res = 0
        def rangeLeaf(node, curStr):
            nonlocal res
            if not node.left and not node.right:
                res += int(curStr, 2)
            if node.left:
                rangeLeaf(node.left, curStr + str(node.left.val))
            if node.right:
                rangeLeaf(node.right, curStr + str(node.right.val))

        rangeLeaf(root, str(root.val))

        return res