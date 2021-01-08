import unittest
from typing import List
import math


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def find_largest_smaller_key(self, root, num):
        def inner(node):
            if node is None:
                return -math.inf
            if node.val > num:
                return inner(node.left)
            else:
                return max(node.val, inner(node.right))
        return inner(root)

    def find_smalest_larger_key(self, root, num):
        def inner(node):
            if node is None:
                return math.inf
            if node.val < num:
                return inner(node.right)
            else:
                return min(node.val, inner(node.left))
        return inner(root)

    def closestValue(self, root: TreeNode, target: float) -> int:
        smaller = self.find_largest_smaller_key(root, target)
        larger = self.find_smalest_larger_key(root, target)
        if abs(smaller - target) < abs(larger - target):
            return smaller
        else:
            return larger


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            4,
            TreeNode(
                2,
                TreeNode(1),
                TreeNode(3)
            ),
            TreeNode(5)
        )
        target = 3.714286
        self.assertEqual(Solution().closestValue(root, target), 4)
