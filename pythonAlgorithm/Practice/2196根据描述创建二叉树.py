# 好家伙我代码没了？？？
# 不需要找出根后再建立，直接建立
# 学到了defaultlist类型可以为任意类型...

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes = defaultdict(TreeNode)
        vals = set()
        for x, y, left in descriptions:
            if left:
                nodes[x].left = nodes[y]
            else:
                nodes[x].right = nodes[y]
            vals.add(y)
        for v, node in nodes.items():
            node.val = v
        return next(node for v, node in nodes.items() if v not in vals)
