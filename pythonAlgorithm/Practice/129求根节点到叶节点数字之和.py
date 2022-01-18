# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.s = 0
        def firstOrder(root, num:int):
            num += root.val
            if not root.left and not root.right:
                self.s += num
                return
            if root.left:
                firstOrder(root.left, num*10)
            if root.right:
                firstOrder(root.right, num*10)
        
        firstOrder(root, 0)
        return self.s