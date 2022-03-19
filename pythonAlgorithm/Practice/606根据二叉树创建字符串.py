# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        self.res = ""
        def firstOrder(root):
            if not root:
                return
            
            self.res += str(root.val)
            if root.left or root.right:
                self.res += '('
                firstOrder(root.left)
                self.res += ')'
            if root.right:
                self.res += '('
                firstOrder(root.right)
                self.res += ')'
            

        firstOrder(root)

        return self.res