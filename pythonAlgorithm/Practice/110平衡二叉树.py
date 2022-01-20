# 后序遍历

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        self.flag = True

        def lastOrder(root: TreeNode) -> int:
            if not root:
                return 0
            lh = lastOrder(root.left)
            rh = lastOrder(root.right)

            if abs(lh - rh) > 1:
                self.flag = False

            return max(lh, rh) + 1

        lastOrder(root)

        return self.flag 