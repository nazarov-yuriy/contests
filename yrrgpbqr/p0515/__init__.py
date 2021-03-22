import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        res = []

        def walk(node, depth):
            if node is None:
                return
            if depth == len(res):
                res.append(node.val)
            else:
                res[depth] = max(res[depth], node.val)
            walk(node.left, depth + 1)
            walk(node.right, depth + 1)

        walk(root, 0)
        return res


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            1,
            TreeNode(
                3,
                TreeNode(5),
                TreeNode(3)
            ),
            TreeNode(
                2,
                None,
                TreeNode(9)
            )
        )
        out = [1, 3, 9]
        self.assertEqual(Solution().largestValues(root), out)
