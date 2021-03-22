import unittest
from typing import List
import random
import collections


class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.items = []
        self.positions = {}

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.positions:
            return False
        self.positions[val] = len(self.items)
        self.items.append(val)
        return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val not in self.positions:
            return False
        last = self.items.pop()
        if last != val:
            self.items[self.positions[val]] = last
            self.positions[last] = self.positions[val]
        del self.positions[val]
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        return self.items[int(random.random() * len(self.items))]


class Test(unittest.TestCase):
    def test(self):
        obj = RandomizedSet()
        self.assertEqual(obj.insert(1), True)
        self.assertEqual(obj.insert(1), False)
        obj.insert(2)
        self.assertEqual(obj.remove(1), True)
        self.assertEqual(obj.remove(3), False)
        obj.insert(3)
        obj.insert(4)
        c = collections.Counter()
        for i in range(1000):
            c[obj.getRandom()] += 1
        assert c[2] >= 300
        assert c[3] >= 300
        assert c[4] >= 300
