import unittest
from typing import List


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []


class Solution:
    def findRoot(self, tree: List['Node']) -> 'Node':
        root_val = 0
        for node in tree:
            root_val ^= node.val
            for child in node.children:
                root_val ^= child.val
        for node in tree:
            if node.val == root_val:
                return node


class Test(unittest.TestCase):
    def test(self):
        root = Node(
            1,
            [
                Node(2),
                Node(
                    3,
                    [
                        Node(6),
                        Node(7),
                    ]
                ),
                Node(4),
                Node(5),
            ]
        )
        self.assertEqual(
            Solution().findRoot([root] + root.children + [x for child in root.children for x in child.children]),
            root
        )
