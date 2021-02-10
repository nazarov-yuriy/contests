import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        nodes_sum = 0
        def walk(node):
            nonlocal nodes_sum
            if node:
                walk(node.right)
                nodes_sum += node.val
                node.val = nodes_sum
                walk(node.left)
        walk(root)
        return root


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            2,
            TreeNode(1),
            TreeNode(3)
        )
        Solution().convertBST(root)
        self.assertEqual(root.left.val, 6)
        self.assertEqual(root.val, 5)
        self.assertEqual(root.right.val, 3)