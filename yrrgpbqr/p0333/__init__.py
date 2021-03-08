import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def largestBSTSubtree(self, root: TreeNode) -> int:
        def inner(node):
            if node is None:
                return (True, 0, None, None)
            left_is_bst, left_size, left_min, left_max = inner(node.left)
            right_is_bst, right_size, right_min, right_max = inner(node.right)
            if left_is_bst and right_is_bst and (left_max is None or left_max < node.val) and (
                    right_min is None or node.val < right_min):
                return True, left_size + right_size + 1, left_min if left_min is not None else node.val, right_max if right_max is not None else node.val
            else:
                return False, max(left_size, right_size), left_min if left_min is not None else node.val, right_max if right_max is not None else node.val

        return inner(root)[1]


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            10,
            TreeNode(5, TreeNode(1), TreeNode(8)),
            TreeNode(15, None, TreeNode(7))
        )
        self.assertEqual(Solution().largestBSTSubtree(root), 3)
