import unittest
from typing import List
import random
import collections


class RandomizedCollection:
    def __init__(self):
        self.hashmap = {}
        self.list = []

    def insert(self, val: int) -> bool:
        res = val not in self.hashmap
        self.hashmap.setdefault(val, set()).add(len(self.list))
        self.list.append(val)
        return res

    def remove(self, val: int) -> bool:
        if val not in self.hashmap:
            return False
        last_pos = len(self.list) - 1
        to_move = self.list.pop()
        if to_move == val:
            self.hashmap[val].remove(last_pos)
        else:
            pos = next(iter(self.hashmap[val]))
            self.hashmap[val].remove(pos)
            self.list[pos] = to_move
            self.hashmap[self.list[pos]].remove(last_pos)
            self.hashmap[self.list[pos]].add(pos)
        if len(self.hashmap[val]) == 0:
            del self.hashmap[val]
        return True

    def getRandom(self) -> int:
        pos = random.randint(0, len(self.list) - 1)
        return self.list[pos]


class Test(unittest.TestCase):
    def test(self):
        obj = RandomizedCollection()
        obj.insert(1)
        obj.remove(1)
        obj.insert(1)
        # print(obj.hashmap, obj.list)
        obj.insert(2)
        # print(obj.hashmap, obj.list)
        obj.remove(1)
        # print(obj.hashmap, obj.list)
        obj.insert(2)
        # print(obj.hashmap, obj.list)
        obj.insert(3)
        # print(obj.hashmap, obj.list)
        obj.getRandom()
        c = collections.Counter()
        for _ in range(10000):
            num = obj.getRandom()
            c[num] += 1
        # print(c)
        self.assertEqual(0.45 < c[3] / c[2] < 0.55, True)
