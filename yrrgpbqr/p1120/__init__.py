import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        res = 0

        def inner(node):
            if node is None:
                return 0, 0
            left = inner(node.left)
            right = inner(node.right)
            sum_val = left[0] + right[0] + node.val
            count = left[1] + right[1] + 1
            nonlocal res
            res = max(res, sum_val / count)
            return sum_val, count

        inner(root)
        return res


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            5,
            TreeNode(6),
            TreeNode(1)
        )
        out = 6
        self.assertEqual(Solution().maximumAverageSubtree(root), out)
