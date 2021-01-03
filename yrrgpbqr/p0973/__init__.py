import unittest
from typing import List


class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        return sorted(points, key=lambda x: x[0]**2 + x[1]**2)[:K]


class Test(unittest.TestCase):
    def test(self):
        points = [[3, 3], [5, -1], [-2, 4]]
        K = 2
        self.assertEqual(
            Solution().kClosest(points, K),
            [[3, 3], [-2, 4]]
        )
