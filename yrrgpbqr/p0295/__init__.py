import unittest
from typing import List
import heapq


class MedianFinder:
    def __init__(self):
        self.lh = []
        self.uh = []
        self.median = 0

    def addNum(self, num: int) -> None:
        if num >= self.median:
            heapq.heappush(self.uh, num)
        else:
            heapq.heappush(self.lh, -num)
        if len(self.uh) - len(self.lh) > 1:
            heapq.heappush(self.lh, -heapq.heappop(self.uh))
        elif len(self.lh) - len(self.uh) > 0:
            heapq.heappush(self.uh, -heapq.heappop(self.lh))
        if len(self.lh) == len(self.uh):
            self.median = (-self.lh[0] + self.uh[0]) / 2
        else:
            self.median = self.uh[0]

    def findMedian(self) -> float:
        return self.median


class Test(unittest.TestCase):
    def test(self):
        obj = MedianFinder()
        obj.addNum(1)
        obj.addNum(2)
        self.assertEqual(obj.findMedian(), 1.5)
        obj.addNum(3)
        self.assertEqual(obj.findMedian(), 2)
