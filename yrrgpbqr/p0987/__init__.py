import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        positions = {}
        def walk(node, x, y):
            positions.setdefault(x, []).append((-y, node.val))
            if node.left is not None:
                walk(node.left, x-1, y-1)
            if node.right is not None:
                walk(node.right, x+1, y-1)
        if root is not None:
            walk(root, 0, 0)
        res = []
        for x in sorted(positions):
            res.append([v for y, v in sorted(positions[x])])
        return res


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            3,
            TreeNode(9),
            TreeNode(
                20,
                TreeNode(15),
                TreeNode(7),
            ),
        )
        self.assertEqual(Solution().verticalTraversal(root), [[9], [3, 15], [20], [7]])
        root = TreeNode(
            1,
            TreeNode(
                2,
                TreeNode(4),
                TreeNode(5),
            ),
            TreeNode(
                3,
                TreeNode(6),
                TreeNode(7),
            ),
        )
        self.assertEqual(Solution().verticalTraversal(root), [[4], [2], [1, 5, 6], [3], [7]])
