"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        res = [[root.val]]
        cur = [root]
        while cur:
            temp, tres = [], []
            for p in cur:
                for child in p.children:
                    temp.append(child)
                    tres.append(child.val)

            cur = temp
            if tres:
                res.append(tres)

        return res        