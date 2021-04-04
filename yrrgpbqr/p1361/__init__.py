import unittest
from typing import List
import itertools


class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        root = set(range(n))
        for child in itertools.chain(leftChild, rightChild):
            root.discard(child)
        if len(root) != 1:
            return False
        seen = set()
        res = True

        def walk(node):
            nonlocal res
            if node == -1:
                return
            if node in seen:
                res = False
                return
            seen.add(node)
            walk(leftChild[node])
            walk(rightChild[node])

        walk(next(iter(root)))
        if res and len(seen) == n:
            return True
        else:
            return False


class Test(unittest.TestCase):
    def test(self):
        n = 4
        leftChild = [1, -1, 3, -1]
        rightChild = [2, -1, -1, -1]
        out = True
        self.assertEqual(Solution().validateBinaryTreeNodes(n, leftChild, rightChild), out)
        n = 4
        leftChild = [1, -1, 3, -1]
        rightChild = [2, 3, -1, -1]
        out = False
        self.assertEqual(Solution().validateBinaryTreeNodes(n, leftChild, rightChild), out)
        n = 2
        leftChild = [1, 0]
        rightChild = [-1, -1]
        out = False
        self.assertEqual(Solution().validateBinaryTreeNodes(n, leftChild, rightChild), out)
        n = 6
        leftChild = [1, -1, -1, 4, -1, -1]
        rightChild = [2, -1, -1, 5, -1, -1]
        out = False
        self.assertEqual(Solution().validateBinaryTreeNodes(n, leftChild, rightChild), out)
