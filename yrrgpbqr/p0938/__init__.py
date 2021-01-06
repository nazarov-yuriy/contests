import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        def walk(node):
            res = 0
            if low <= node.val <= high:
                res += node.val
            if node.val <= high and node.right is not None:
                res += walk(node.right)
            if low <= node.val and node.left is not None:
                res += walk(node.left)
            return res
        if root is None:
            return 0
        else:
            return walk(root)


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            10,
            TreeNode(
                5,
                TreeNode(3),
                TreeNode(7)
            ),
            TreeNode(
                15,
                None,
                TreeNode(18)
            )
        )
        self.assertEqual(Solution().rangeSumBST(root, 7, 15), 32)
        root = TreeNode(
            10,
            TreeNode(
                5,
                TreeNode(
                    3,
                    TreeNode(1)
                ),
                TreeNode(
                    7,
                    TreeNode(6)
                )
            ),
            TreeNode(
                15,
                TreeNode(13),
                TreeNode(18)
            )
        )
        self.assertEqual(Solution().rangeSumBST(root, 6, 10), 23)
