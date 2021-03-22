import unittest
from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 0, max(piles)
        while r - l > 1:
            m = (l + r) // 2
            if sum((x + m - 1) // m for x in piles) > h:
                l = m
            else:
                r = m
        return r


class Test(unittest.TestCase):
    def test(self):
        piles = [3, 6, 7, 11]
        h = 8
        out = 4
        self.assertEqual(Solution().minEatingSpeed(piles, h), out)
        piles = [30, 11, 23, 4, 20]
        h = 5
        out = 30
        self.assertEqual(Solution().minEatingSpeed(piles, h), out)
        piles = [30, 11, 23, 4, 20]
        h = 6
        out = 23
        self.assertEqual(Solution().minEatingSpeed(piles, h), out)
