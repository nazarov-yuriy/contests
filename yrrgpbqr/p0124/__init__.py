import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        res = [-1e9]
        def walk(node):
            l_res, r_res = 0, 0
            if node.left:
                l_res = walk(node.left)
            if node.right:
                r_res = walk(node.right)
            res[0] = max(res[0], node.val + max(0, l_res) + max(0, r_res))
            return node.val + max(0, l_res, r_res)
        walk(root)
        return res[0]



class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            1,
            TreeNode(2),
            TreeNode(3)
        )
        self.assertEqual(Solution().maxPathSum(root), 6)
        root = TreeNode(
            -10,
            TreeNode(9),
            TreeNode(
                20,
                TreeNode(15),
                TreeNode(7)
            )
        )
        self.assertEqual(Solution().maxPathSum(root), 42)
        root = TreeNode(
            -1,
            TreeNode(-2),
            TreeNode(-3)
        )
        self.assertEqual(Solution().maxPathSum(root), -1)
