import unittest
from typing import List


class NestedInteger:
   def __init__(self, value=None):
       """
       If value is not specified, initializes an empty list.
       Otherwise initializes a single integer equal to value.
       """
       self.value = value

   def isInteger(self):
       """
       @return True if this NestedInteger holds a single integer, rather than a nested list.
       :rtype bool
       """
       return isinstance(self.value, int)

   def add(self, elem):
       """
       Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
       :rtype void
       """
       elf.val.append(elem)

   def setInteger(self, value):
       """
       Set this NestedInteger to hold a single integer equal to value.
       :rtype void
       """
       self.value = value

   def getInteger(self):
       """
       @return the single integer that this NestedInteger holds, if it holds a single integer
       Return None if this NestedInteger holds a nested list
       :rtype int
       """
       return self.value

   def getList(self):
       """
       @return the nested list that this NestedInteger holds, if it holds a nested list
       Return None if this NestedInteger holds a single integer
       :rtype List[NestedInteger]
       """
       return self.value


class Solution:
    def depthSum(self, nestedList: List[NestedInteger]) -> int:
        def inner(val, depth):
            if val.isInteger():
                return val.getInteger() * depth
            else:
                return sum(inner(x, depth + 1) for x in val.getList())
        return sum(inner(x, 1) for x in nestedList)


class Test(unittest.TestCase):
    def test(self):
        ni = [
            NestedInteger([NestedInteger(1), NestedInteger(1)]),
            NestedInteger(2),
            NestedInteger([NestedInteger(1), NestedInteger(1)])
        ]
        self.assertEqual(Solution().depthSum(ni), 10)
        ni = [
            NestedInteger(1),
            NestedInteger([
                NestedInteger(4),
                NestedInteger([
                    NestedInteger(6),
                ]),
            ]),
        ]
        self.assertEqual(Solution().depthSum(ni), 27)
