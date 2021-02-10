import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def trimBST(self, root: TreeNode, low: int, high: int) -> TreeNode:
        # trim low
        new_root = TreeNode(10 ** 4 + 1, root)
        node = new_root
        while node.left and node.left.val >= low:
            node = node.left
        if node.left:
            node.left = self.trimBST(node.left.right, low, high)
        # trim high
        new_root = TreeNode(-1, None, new_root.left)
        node = new_root
        while node.right and node.right.val <= high:
            node = node.right
        if node.right:
            node.right = self.trimBST(node.right.left, low, high)
        return new_root.right


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            1,
            TreeNode(0),
            TreeNode(2)
        )
        new_root = Solution().trimBST(root, 1, 2)
        self.assertEqual(new_root.left, None)
        self.assertEqual(new_root.val, 1)
        self.assertEqual(new_root.right.val, 2)
