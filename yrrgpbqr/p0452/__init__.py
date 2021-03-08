import unittest
from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if len(points) == 0:
            return 0
        res = 1
        min_right = points[0][1]
        for point in sorted(points):
            if point[0] <= min_right:
                min_right = min(min_right, point[1])
            else:
                res += 1
                min_right = point[1]
        return res


class Test(unittest.TestCase):
    def test(self):
        points = [[1, 2], [3, 4], [5, 6], [7, 8]]
        out = 4
        self.assertEqual(Solution().findMinArrowShots(points), out)
        points = [[1, 2], [2, 3], [3, 4], [4, 5]]
        out = 2
        self.assertEqual(Solution().findMinArrowShots(points), out)
        points = [[1, 2]]
        out = 1
        self.assertEqual(Solution().findMinArrowShots(points), out)
        points = [[2, 3], [2, 3]]
        out = 1
        self.assertEqual(Solution().findMinArrowShots(points), out)
