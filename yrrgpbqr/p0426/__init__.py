import unittest
from typing import List


class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        def walk(node):
            l, r = node, node
            if node.left is not None:
                l, m = walk(node.left)
                m.right = node
                node.left = m
            if node.right is not None:
                m, r = walk(node.right)
                node.right = m
                m.left = node
            return l, r
        if root is None:
            return None
        else:
            l, r = walk(root)
            r.right = l
            l.left = r
            return l


class Test(unittest.TestCase):
    def test(self):
        root = Node(
            4,
            Node(
                2,
                Node(1),
                Node(3)
            ),
            Node(5)
        )
        head = Solution().treeToDoublyList(root)
        self.assertEqual(
            [head.val, head.right.val, head.right.right.val, head.right.right.right.val,
             head.right.right.right.right.val, head.right.right.right.right.right.val],
            [1, 2, 3, 4, 5, 1]
        )
        self.assertEqual(Solution().treeToDoublyList(None), None)
