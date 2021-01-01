import unittest
from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        if len(heights) == 0:
            return 0

        def getLeftBorders(heights):
            stack = []
            prev = -1
            left_borders = []
            for pos in range(len(heights)):
                if heights[pos] > prev:
                    stack.append([pos, heights[pos]])

                stack[-1][1] = min(stack[-1][1], heights[pos])
                while len(stack) > 0 and stack[-1][1] >= stack[-2][1]:
                    stack.pop()
                    stack[-1][1] = heights[pos]
                left_borders.append(stack[-1][0])
            return left_borders

        left_borders = getLeftBorders(heights)
        right_borders = [len(heights) - 1 - x for x in reversed(getLeftBorders(list(reversed(heights))))]
        return max(
            h * (r - l + 1) for h, l, r in zip(heights, left_borders, right_borders)
        )


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            Solution().largestRectangleArea([10, 11, 10]),
            30
        )
        self.assertEqual(
            Solution().largestRectangleArea([1, 10, 11, 10, 1]),
            30
        )
        self.assertEqual(
            Solution().largestRectangleArea([1, 2, 3, 4, 5, 6, 7]),
            16
        )
        self.assertEqual(
            Solution().largestRectangleArea([2, 1, 5, 6, 2, 3]),
            10
        )
        self.assertEqual(
            Solution().largestRectangleArea([11, 10, 11, 10, 11]),
            50
        )
        self.assertEqual(
            Solution().largestRectangleArea([0, 11, 10]),
            20
        )
        self.assertEqual(
            Solution().largestRectangleArea([10]),
            10
        )
        self.assertEqual(
            Solution().largestRectangleArea([]),
            0
        )
        self.assertEqual(
            Solution().largestRectangleArea([0]),
            0
        )
        self.assertEqual(
            Solution().largestRectangleArea([2, 2, 1, 2, 2]),
            5
        )
        self.assertEqual(
            Solution().largestRectangleArea([2, 2, 1, 1, 2, 2, 0, 2, 2, 1, 2, 2]),
            6
        )
