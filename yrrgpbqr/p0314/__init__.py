import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        positions = {}
        order = 0
        def walk(node, x, y):
            nonlocal order
            positions.setdefault(x, []).append((-y, order, node.val))
            order += 1
            if node.left is not None:
                walk(node.left, x-1, y-1)
            if node.right is not None:
                walk(node.right, x+1, y-1)
        if root is not None:
            walk(root, 0, 0)
        res = []
        for x in sorted(positions):
            res.append([v for y, o, v in sorted(positions[x])])
        return res

class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(1)
        self.assertEqual(Solution().verticalOrder(root), [[1]])
