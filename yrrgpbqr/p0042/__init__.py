import unittest
from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) == 0:
            return 0
        left_max = [height[0]]
        for h in height[1:]:
            left_max.append(max(left_max[-1], h))
        right_max_reversed = [height[-1]]
        for h in reversed(height[:-1]):
            right_max_reversed.append(max(right_max_reversed[-1], h))
        right_max = list(reversed(right_max_reversed))
        res = 0
        for i, h in enumerate(height):
            bounds_h = min(left_max[i], right_max[i])
            if bounds_h > h:
                res += bounds_h - h
        return res



class Test(unittest.TestCase):
    def test(self):
        height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
        self.assertEqual(Solution().trap(height), 6)
        height = [4, 2, 0, 3, 2, 5]
        self.assertEqual(Solution().trap(height), 9)