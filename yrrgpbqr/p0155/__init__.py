import unittest
from typing import List


class MinStack:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []  # (val, min)

    def push(self, x: int) -> None:
        if len(self.stack) > 0:
            min_val = min(x, self.getMin())
        else:
            min_val = x
        self.stack.append((x, min_val))

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]


class Test(unittest.TestCase):
    def test(self):
        obj = MinStack()
        obj.push(1)
        self.assertEqual(obj.top(), 1)
        self.assertEqual(obj.getMin(), 1)
        obj.push(0)
        self.assertEqual(obj.top(), 0)
        self.assertEqual(obj.getMin(), 0)
        obj.pop()
        self.assertEqual(obj.top(), 1)
        self.assertEqual(obj.getMin(), 1)
