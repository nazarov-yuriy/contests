import unittest
from typing import List


class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(candyType) // 2, len(set(candyType)))


class Test(unittest.TestCase):
    def test(self):
        candyType = [1, 1, 2, 2, 3, 3]
        out = 3
        self.assertEqual(Solution().distributeCandies(candyType), out)
