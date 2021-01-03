import unittest
from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        to_close = set()
        pos = 0
        start = None
        res = []
        for interval in sorted(intervals):
            while pos < interval[0]:
                if pos in to_close:
                    if len(to_close) == 1:  # last
                        res.append([start, pos])
                    to_close.remove(pos)
                pos += 1
            if len(to_close) == 0:  # first
                start = interval[0]
            to_close.add(interval[1])
        if to_close:
            res.append([start, max(to_close)])

        return res


class Test(unittest.TestCase):
    def test(self):
        intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
        self.assertEqual(
            Solution().merge(intervals),
            [[1, 6], [8, 10], [15, 18]]
        )
        intervals = [[1, 4], [4, 5]]
        self.assertEqual(
            Solution().merge(intervals),
            [[1, 5]]
        )
        intervals = [[0, 4], [4, 5]]
        self.assertEqual(
            Solution().merge(intervals),
            [[0, 5]]
        )
        intervals = [[42, 42]]
        self.assertEqual(
            Solution().merge(intervals),
            [[42, 42]]
        )