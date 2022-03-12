class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        res = []

        def helper(root):
            if not root:
                return
            for child in root.children:
                helper(child)
            res.append(root.val)
        helper(root)

        return res
