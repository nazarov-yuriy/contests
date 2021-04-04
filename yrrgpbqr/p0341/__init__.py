import unittest
from typing import List


class NestedInteger:
    def __init__(self, val):
        self.val = val

    def isInteger(self) -> bool:
        """
        @return True if this NestedInteger holds a single integer, rather than a nested list.
        """
        return isinstance(self.val, int)

    def getInteger(self) -> int:
        """
        @return the single integer that this NestedInteger holds, if it holds a single integer
        Return None if this NestedInteger holds a nested list
        """
        if self.isInteger():
            return self.val
        return None

    def getList(self) -> ["NestedInteger"]:
        """
        @return the nested list that this NestedInteger holds, if it holds a nested list
        Return None if this NestedInteger holds a single integer
        """
        if self.isInteger():
            return None
        return [NestedInteger(x) for x in self.val]


class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.stack = []
        self.stack.append([nestedList, 0])
        self._next = None
        self.next()

    def next(self) -> int:
        res = self._next
        self._next = None
        while len(self.stack):
            if self.stack[-1][1] < len(self.stack[-1][0]):
                if self.stack[-1][0][self.stack[-1][1]].isInteger():
                    self._next = self.stack[-1][0][self.stack[-1][1]].getInteger()
                    self.stack[-1][1] += 1
                    break
                else:
                    self.stack.append([self.stack[-1][0][self.stack[-1][1]].getList(), 0])
            else:
                self.stack.pop()
                if len(self.stack):
                    self.stack[-1][1] += 1
        return res

    def hasNext(self) -> bool:
        return self._next is not None


class Test(unittest.TestCase):
    def test(self):
        nestedList = [[1, 1], 2, [1, 1]]
        it = NestedIterator([NestedInteger(x) for x in nestedList])
        self.assertEqual(it.next(), 1)
        self.assertEqual(it.next(), 1)
        self.assertEqual(it.next(), 2)
        self.assertEqual(it.next(), 1)
        self.assertEqual(it.next(), 1)
        self.assertEqual(it.hasNext(), False)
