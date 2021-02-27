import unittest
from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        max_depth = 0

        def walk(node, depth):
            if node is None:
                return
            nonlocal max_depth
            max_depth = max(max_depth, depth)
            walk(node.left, depth + 1)
            walk(node.right, depth + 1)

        walk(root, 1)
        return max_depth


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            3,
            TreeNode(9),
            TreeNode(
                20,
                TreeNode(15),
                TreeNode(7)
            )
        )
        out = 3
        self.assertEqual(Solution().maxDepth(root), out)
