# set表维护
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        s = set()
        def firstOrder(root):

            if not root:
                return False

            if (k - root.val) in s:
                return True

            s.add(root.val)

            return firstOrder(root.left) or firstOrder(root.right)

        return firstOrder(root)


# 利用bst性质，把树转化为升序数组
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        arr = []
        def inorderTraversal(node: Optional[TreeNode]) -> None:
            if node:
                inorderTraversal(node.left)
                arr.append(node.val)
                inorderTraversal(node.right)
        inorderTraversal(root)

        left, right = 0, len(arr) - 1
        while left < right:
            sum = arr[left] + arr[right]
            if sum == k:
                return True
            if sum < k:
                left += 1
            else:
                right -= 1
        return False
