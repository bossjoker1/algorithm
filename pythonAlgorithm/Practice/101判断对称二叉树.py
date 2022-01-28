# 简单题不简单

# 递归
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True

        def cmp(root1:TreeNode, root2:TreeNode) -> bool:
            if not root1 and not root2:
                return True

            if not root1 or not root2 or root1.val != root2.val:
                return False

            return cmp(root1.left, root2.right) and cmp(root1.right, root2.left)

        return cmp(root.left, root.right) 
    
# 迭代
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        q = collections.deque([])
        q.append(root.left)
        q.append(root.right)
        while q:
            left = q.popleft()
            right = q.popleft()
            if not left and not right:
                continue

            if not left or not right:
                return False

            if left.val != right.val:
                return False

            q.append(left.left)
            q.append(right.right)
            q.append(left.right)
            q.append(right.left)
        return True

