import unittest
from typing import List


class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        max_height = -1
        rev_res = []
        for i in reversed(range(len(heights))):
            h = heights[i]
            if h > max_height:
                rev_res.append(i)
            max_height = max(max_height, h)
        return list(reversed(rev_res))


class Test(unittest.TestCase):
    def test(self):
        heights = [4, 2, 3, 1]
        out = [0, 2, 3]
        self.assertEqual(Solution().findBuildings(heights), out)
        heights = [4, 3, 2, 1]
        out = [0, 1, 2, 3]
        self.assertEqual(Solution().findBuildings(heights), out)
        heights = [1, 3, 2, 4]
        out = [3]
        self.assertEqual(Solution().findBuildings(heights), out)
        heights = [2, 2, 2, 2]
        out = [3]
        self.assertEqual(Solution().findBuildings(heights), out)
