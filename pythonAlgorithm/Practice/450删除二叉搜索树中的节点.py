# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None
        if root.val > key:
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        elif root.left is None or root.right is None:
            root = root.left if root.left else root.right
        else:
            # 删除节点同时包含左右子树
            # 找到右子树的最小节点作为替代
            successor = root.right
            while successor.left:
                successor = successor.left
            # 需要先删除该节点，又是一个找其父节点的过程
            successor.right = self.deleteNode(root.right, successor.val)
            successor.left = root.left
            return successor
        return root
