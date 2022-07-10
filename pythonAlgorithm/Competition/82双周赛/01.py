# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
from typing import *
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        if not root:return 1
        if root.val == 1:return True
        elif root.val == 0:return False
        return self.evaluateTree(root.left) or self.evaluateTree(root.right) if root.val == 2 else self.evaluateTree(root.left) and self.evaluateTree(root.right)