import unittest
from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = len(height), 0
        res = 0
        for h, i in sorted([(h, i) for i, h in enumerate(height)], reverse=True):
            l = min(l, i)
            r = max(r, i)
            volume = max(h * (i - l), h * (r - i))
            res = max(res, volume)
        return res


class Test(unittest.TestCase):
    def test(self):
        height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
        out = 49
        self.assertEqual(Solution().maxArea(height), out)
