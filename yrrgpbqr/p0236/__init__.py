import unittest
from typing import List


class TreeNode:
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        lca = None
        def nodes_found(node):
            if node is None:
                return 0
            res = nodes_found(node.left) + nodes_found(node.right)
            if node is p or node is q:
                res += 1
            nonlocal lca
            if res == 2 and lca is None:
                lca = node
            return res
        nodes_found(root)
        return lca


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            3,
            TreeNode(
                5,
                TreeNode(6),
                TreeNode(
                    2,
                    TreeNode(7),
                    TreeNode(4)
                )
            ),
            TreeNode(
                1,
                TreeNode(0),
                TreeNode(8)
            )
        )
        self.assertEqual(Solution().lowestCommonAncestor(root, root.left.left, root.left.right), root.left)
        self.assertEqual(Solution().lowestCommonAncestor(root, root.left, root.left.right.right), root.left)
