# bfs 层序遍历的序列化与反序列化
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root == None:
            return ""

        res = []
        q = collections.deque()
        q.append(root)
        while q:
            x = q.popleft()
            if x: 
                res.append(str(x.val))
                q.append(x.left)
                q.append(x.right)
            else:
                res.append('None')

        return ','.join(res)


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == "":
            return None

        data = data.split(",")
        root = TreeNode(int(data[0]))
        q = collections.deque()
        q.append(root)
        idx = 1
        while q:
            x = q.popleft()
            if data[idx] != 'None':
                x.left = TreeNode(int(data[idx]))
                q.append(x.left)
            idx += 1
            if data[idx] != 'None':
                x.right = TreeNode(int(data[idx]))
                q.append(x.right)
            idx += 1
        
        return root



# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
