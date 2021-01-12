import unittest
from typing import List


class TreeNode:
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right


class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        node = root
        stack = []
        while node.val != p.val:
            stack.append(node)
            if node.val > p.val:
                node = node.left
            else:
                node = node.right

        if node.right is not None:
            node = node.right
            while node.left is not None:
                node = node.left
        else:
            while len(stack) > 0 and stack[-1].right == node:
                node = stack.pop()
            if len(stack) > 0:
                node = stack.pop()
            else:
                node = None
        return node


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            1,
            TreeNode(0),
            TreeNode(2)
        )
        self.assertEqual(Solution().inorderSuccessor(root, root.left), root)
        self.assertEqual(Solution().inorderSuccessor(root, root), root.right)
        self.assertEqual(Solution().inorderSuccessor(root, root.right), None)
