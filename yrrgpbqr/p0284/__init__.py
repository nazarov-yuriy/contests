import unittest
from typing import List


class Iterator:
    def __init__(self, nums):
        """
        Initializes an iterator object to the beginning of a list.
        :type nums: List[int]
        """
        self.nums = nums
        self.pos = 0

    def hasNext(self):
        """
        Returns true if the iteration has more elements.
        :rtype: bool
        """
        return self.pos < len(self.nums)

    def next(self):
        """
        Returns the next element in the iteration.
        :rtype: int
        """
        res = self.nums[self.pos]
        self.pos += 1
        return res


class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self._next = None
        self.next()

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        return self._next

    def next(self):
        """
        :rtype: int
        """
        res = self._next
        self._has_next = self.iterator.hasNext()
        self._next = self.iterator.next() if self._has_next else None
        return res

    def hasNext(self):
        """
        :rtype: bool
        """
        return self._has_next


class Test(unittest.TestCase):
    def test(self):
        nums = [1, 2, 3]
        pi = PeekingIterator(Iterator(nums))
        self.assertEqual(pi.next(), 1)
        self.assertEqual(pi.peek(), 2)
        self.assertEqual(pi.next(), 2)
        self.assertEqual(pi.next(), 3)
        self.assertEqual(pi.hasNext(), False)
