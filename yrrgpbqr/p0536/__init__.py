import unittest
from typing import List
import math


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def str2tree(self, s: str) -> TreeNode:
        if s == "":
            return None
        stack = [TreeNode()]
        for char in s:
            if '0' <= char <= '9':
                stack[-1].val *= 10
                stack[-1].val += math.copysign(ord(char) - ord('0'), stack[-1].val)
                stack[-1].val = int(stack[-1].val)
            elif '(' == char:
                stack.append(TreeNode())
                if stack[-2].left is None:
                    stack[-2].left = stack[-1]
                else:
                    stack[-2].right = stack[-1]
            elif ')' == char:
                stack.pop()
            elif '-' == char:
                stack[-1].val = -0.0
            else:
                assert False
        return stack[0]


class Test(unittest.TestCase):
    def test(self):
        s = "4(2(3)(1))(6(5))"
        tree = Solution().str2tree(s)
        self.assertEqual(tree.val, 4)
        self.assertEqual(tree.left.val, 2)
        self.assertEqual(tree.right.val, 6)
        self.assertEqual(tree.left.left.val, 3)
        self.assertEqual(tree.left.right.val, 1)
        self.assertEqual(tree.right.left.val, 5)
        s = "-4(2(3)(1))(6(5))"
        tree = Solution().str2tree(s)
        self.assertEqual(tree.val, -4)
        self.assertEqual(tree.left.val, 2)
        self.assertEqual(tree.right.val, 6)
        self.assertEqual(tree.left.left.val, 3)
        self.assertEqual(tree.left.right.val, 1)
        self.assertEqual(tree.right.left.val, 5)
