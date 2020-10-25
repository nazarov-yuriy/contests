from typing import List
import unittest
import math

class Solution:
    EPS = 1e-9

    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        near_res = 0
        distant_points = []
        for x, y in points:
            if x == location[0] and y == location[1]:
                near_res += 1
            else:
                distant_points.append((x, y))

        angles = sorted([math.atan2(y - location[1], x - location[0]) / math.pi * 180 + 180 for x, y in distant_points])
        double_angles = angles + [angle + 360 for angle in angles]

        distant_res = 0
        left_pos = 0
        for right_pos, right_angle in enumerate(angles):
            while left_pos + 1 < len(double_angles) and double_angles[left_pos + 1] <= right_angle + angle + self.EPS:
                left_pos += 1
            distant_res = max(distant_res, left_pos - right_pos + 1)

        return near_res + distant_res

class Test(unittest.TestCase):
    def test(self):
        points = [[1, 1], [1, -1], [-1, 1], [-1, -1]]
        angle = 90
        location = [0, 0]
        self.assertEqual(Solution().visiblePoints(points, angle, location), 2)

        points = [[2, 1], [2, 2], [3, 3]]
        angle = 90
        location = [1, 1]
        self.assertEqual(Solution().visiblePoints(points, angle, location), 3)

        points = [[2,1],[2,2],[3,4],[1,1]]
        angle = 90
        location = [1, 1]
        self.assertEqual(Solution().visiblePoints(points, angle, location), 4)
