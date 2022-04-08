# 体会递归的思想
class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        # 递归匹配函数
        def recur(A, B):
            if not B: return True
            if not A or A.val != B.val: return False
            return recur(A.left, B.left) and recur(A.right, B.right)

        # B是A以A为根节点的树的子结构
        # B是以A左节点为根的树的子结构
        # B是以A右节点为根的树的子结构
        return bool(A and B) and (recur(A, B) or self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B))