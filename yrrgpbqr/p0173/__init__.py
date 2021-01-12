import unittest
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BSTIterator:
    def __init__(self, root: TreeNode):
        self.node = root
        self.stack = []
        while self.node.left is not None:
            self.stack.append(self.node)
            self.node = self.node.left


    def next(self) -> int:
        if self.node is None:
            raise StopIteration()
        res = self.node

        if self.node.right is not None:
            self.stack.append(self.node)
            self.node = self.node.right
            while self.node.left is not None:
                self.stack.append(self.node)
                self.node = self.node.left
        else:
            while len(self.stack) > 0 and self.stack[-1].right == self.node:
                self.node = self.stack.pop()
            if len(self.stack) > 0:
                self.node = self.stack.pop()
            else:
                self.node = None
        return res.val

    def hasNext(self) -> bool:
        return self.node is not None


class Test(unittest.TestCase):
    def test(self):
        root = TreeNode(
            1,
            TreeNode(0),
            TreeNode(2),
        )
        obj = BSTIterator(root)
        self.assertEqual(obj.hasNext(), True)
        self.assertEqual(obj.next(), 0)
        self.assertEqual(obj.hasNext(), True)
        self.assertEqual(obj.next(), 1)
        self.assertEqual(obj.hasNext(), True)
        self.assertEqual(obj.next(), 2)
        self.assertEqual(obj.hasNext(), False)
        self.assertRaises(StopIteration, obj.next)
