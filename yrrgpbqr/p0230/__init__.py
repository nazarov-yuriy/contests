import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack = []
        node = root
        while node.left:
            stack.append(node)
            node = node.left
        while k != 1:
            if node.right:
                stack.append(node)
                node = node.right
                while node.left:
                    stack.append(node)
                    node = node.left
            else:
                while stack and stack[-1].right == node:
                    node = stack.pop()
                node = stack.pop()
            k -= 1
        return node.val


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            3,
            TreeNode(1, None, TreeNode(2)),
            TreeNode(4),
        )
        k = 1
        out = 1
        self.assertEqual(Solution().kthSmallest(root, k), out)
        k = 2
        out = 2
        self.assertEqual(Solution().kthSmallest(root, k), out)
        k = 3
        out = 3
        self.assertEqual(Solution().kthSmallest(root, k), out)
        k = 4
        out = 4
        self.assertEqual(Solution().kthSmallest(root, k), out)
