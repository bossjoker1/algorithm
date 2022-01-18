# hard
# 改编可能会出现要你打印路径，不知道咋做
# 想法就是分各种情况考虑全面
# 一般通过是否为根节点进行分类


class Solution:

    res = -sys.maxsize - 1

    def maxPathSum(self, root: Optional[TreeNode]) -> int:

        self.maxValue(root)

        return self.res

    def maxValue(self, root):

        if root == None:
            return 0

        lval = self.maxValue(root.left)
        rval = self.maxValue(root.right)

        val1 = root.val
        val2 = root.val + lval
        val3 = root.val + rval
        val4 = root.val + lval + rval

        # 此节点为根节点
        maxV = max([val1, val2, val3, val4])

        self.res = max(maxV, self.res)

        # 为根节点的情况无法再继续向上传，去除val4
        return max([val1, val2, val3])


# 打印路径：
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.ans = 0
        self.path = [] # 存储路径
        self.dfs(root)
        print(self.path)
        return self.ans
    
    def dfs(self, root): # 返回从该根节点到叶节点最大路径和
        if root is None: return 0, []
        left, leftPath = self.dfs(root.left)
        right, rightPath = self.dfs(root.right)
        
        # 为根节点的情况，直接赋值
        if root.val + left + right > self.ans:
            self.ans = root.val + left + right
            self.path = leftPath + [root.val] + rightPath

        # 左右子树
        if left > 0 and left > right:
            res = left + root.val
            path = leftPath + [root.val]
        elif right > 0 and right > left:
            res = right + root.val
            path = [root.val] + rightPath 
        else:
            res = root.val
            path = [root.val]
        
        # 更新该情况下的值
        if self.ans < res:
            self.ans = res
            self.path = path
            
        return res, path # res 是路径和，path 是路径数组
