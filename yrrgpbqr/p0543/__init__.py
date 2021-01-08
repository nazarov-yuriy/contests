import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        diameter = 0
        def walk(node):
            if node is None:
                return 0
            left_depth = walk(node.left)
            right_depth = walk(node.right)
            nonlocal diameter
            diameter = max(diameter, left_depth + right_depth)
            return max(left_depth, right_depth) + 1
        walk(root)
        return diameter


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            1,
            TreeNode(
                2,
                TreeNode(4),
                TreeNode(5)
            ),
            TreeNode(3)
        )
        self.assertEqual(Solution().diameterOfBinaryTree(root), 3)
