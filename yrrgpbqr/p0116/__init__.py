import unittest
from typing import List


class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        last_node_by_level = {}  # {0: Node(1), 1: Node(3), 2: Node(5)}

        def inner(node, level):
            if node is None:
                return
            node.next = last_node_by_level.get(level)
            last_node_by_level[level] = node
            inner(node.right, level + 1)
            inner(node.left, level + 1)

        inner(root, 0)
        return root


class Test(unittest.TestCase):
    def test(self):
        root = Node(1, Node(2), Node(3))
        Solution().connect(root)
        self.assertEqual(root.left.next, root.right)
