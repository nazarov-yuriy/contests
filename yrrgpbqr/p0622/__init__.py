import unittest
from typing import List


class MyCircularQueue:
    def __init__(self, k: int):
        self.queue = [None] * k
        self.k = k
        self.reads = 0
        self.writes = 0

    def enQueue(self, value: int) -> bool:
        if self.writes + 1 - self.reads > self.k:
            return False
        self.queue[self.writes % self.k] = value
        self.writes += 1
        return True

    def deQueue(self) -> bool:
        if self.reads + 1 - self.writes > 0:
            return False
        # res = self.queue[self.reads % self.k]
        self.reads += 1
        return True

    def Front(self) -> int:
        if self.reads == self.writes:
            return -1
        return self.queue[self.reads % self.k]

    def Rear(self) -> int:
        if self.reads == self.writes:
            return -1
        return self.queue[(self.writes - 1) % self.k]

    def isEmpty(self) -> bool:
        return self.reads == self.writes

    def isFull(self) -> bool:
        return self.writes - self.reads == self.k


class Test(unittest.TestCase):
    def test(self):
        obj = MyCircularQueue(3)
        self.assertEqual(obj.enQueue(1), True)
        self.assertEqual(obj.enQueue(2), True)
        self.assertEqual(obj.enQueue(3), True)
        self.assertEqual(obj.enQueue(4), False)
        self.assertEqual(obj.Rear(), 3)
        self.assertEqual(obj.isFull(), True)
        self.assertEqual(obj.deQueue(), True)
        self.assertEqual(obj.enQueue(4), True)
        self.assertEqual(obj.Rear(), 4)
