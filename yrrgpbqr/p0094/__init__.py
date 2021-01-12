import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        def walk(node):
            if node is not None:
                walk(node.left)
                res.append(node.val)
                walk(node.right)
        walk(root)
        return res


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            1,
            None,
            TreeNode(
                2,
                TreeNode(3)
            )
        )
        self.assertEqual(Solution().inorderTraversal(root), [1,3,2])
