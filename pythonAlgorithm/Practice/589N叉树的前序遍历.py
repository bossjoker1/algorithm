class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        res = []
		
        def helper(root):
            if not root:
                return
            res.append(root.val)
            for child in root.children:
                helper(child)
		
        helper(root)
		
        return res