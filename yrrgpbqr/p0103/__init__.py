import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res = {}

        def walk(node, level):
            if node:
                res.setdefault(level, []).append(node.val)
                walk(node.left, level + 1)
                walk(node.right, level + 1)

        walk(root, 0)
        return [res[level] if level % 2 == 0 else list(reversed(res[level])) for level in sorted(res)]


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(3)
        root.left = TreeNode(9)
        right = TreeNode(20)
        root.right = right
        right.left = TreeNode(15)
        right.right = TreeNode(7)
        self.assertEqual(Solution().zigzagLevelOrder(root), [
            [3],
            [20, 9],
            [15, 7]
        ])
