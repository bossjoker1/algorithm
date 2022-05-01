# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        temp = []
        def Inorder(root:TreeNode):
            if not root:
                return

            Inorder(root.left)
            temp.append(root.val)
            Inorder(root.right)

        Inorder(root1)    
        Inorder(root2)

        return sorted(temp)
    
# 有序序列 + 归并排序
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        res1, res2 = [], []
        def Inorder(root:TreeNode, l:List[int]):
            if not root:
                return

            Inorder(root.left, l)
            l.append(root.val)
            Inorder(root.right, l)

        Inorder(root1, res1)    
        Inorder(root2, res2)

        m, n = len(res1), len(res2)
        i, j = 0, 0
        ans = []
        while i < m or j < n:
            a = res1[i] if i < m else inf
            b = res2[j] if j < n else inf
            if a <= b:
                ans.append(res1[i])
                i += 1
            else:
                ans.append(res2[j])
                j += 1
        
        return ans
