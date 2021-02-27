import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def walk(lnode, rnode):
            if lnode is None and rnode is None:
                return True
            elif lnode is None or rnode is None:
                return False
            return lnode.val == rnode.val and walk(lnode.left, rnode.right) and walk(lnode.right, rnode.left)

        return walk(root, root)


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(1, TreeNode(2), TreeNode(2))
        out = True
        self.assertEqual(Solution().isSymmetric(root), out)
        root = TreeNode(1, TreeNode(2), TreeNode(3))
        out = False
        self.assertEqual(Solution().isSymmetric(root), out)
        root = TreeNode(1, TreeNode(2, TreeNode(3)), TreeNode(2, TreeNode(3)))
        out = False
        self.assertEqual(Solution().isSymmetric(root), out)