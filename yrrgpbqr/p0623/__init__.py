import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            return TreeNode(v, root)

        def inner(node, depth):
            if depth == d:
                node.left = TreeNode(v, node.left)
                node.right = TreeNode(v, None, node.right)
            else:
                if node.left:
                    inner(node.left, depth + 1)
                if node.right:
                    inner(node.right, depth + 1)

        inner(root, 2)
        return root


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            4,
            TreeNode(
                2,
                TreeNode(3),
                TreeNode(1)
            ),
        )
        v = 1
        d = 3
        root = Solution().addOneRow(root, v, d)
        self.assertEqual(root.left.left.val, v)
        self.assertEqual(root.left.right.val, v)
        self.assertEqual(root.left.left.left.val, 3)
        self.assertEqual(root.left.right.right.val, 1)
