# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        self.s = 0
        self.flag = False
        def firstOrder(root):
            # print("flag:%s, val : %d, s : %d"%(self.flag, root.val, self.s))
            self.s += root.val
            if not root.left and not root.right:
                if self.s == targetSum:
                    self.flag = True
                return
            if not self.flag and root.left:
                firstOrder(root.left)
                self.s -= root.left.val
            if not self.flag and root.right:
                firstOrder(root.right)
                self.s -= root.right.val
        
        if root:                        
            firstOrder(root)
        return self.flag


# 评论区的简略写法
# 没有对比就没有差距呜呜呜

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        targetSum -= root.val
        # 叶节点？
        if not root.left and not root.right:
            return targetSum == 0
        return self.hasPathSum(root.left, targetSum) or self.hasPathSum(root.right, targetSum)