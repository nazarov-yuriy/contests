import unittest
from typing import List


class Solution:
    def countCornerRectangles(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        from_to = [[0] * cols for _ in range(cols)]
        res = 0
        for row in range(rows):
            for i in range(0, cols - 1):
                if grid[row][i] == 1:
                    for j in range(i + 1, cols):
                        if grid[row][j] == 1:
                            from_to[i][j] += 1
        res = 0
        for i in range(0, cols - 1):
            for j in range(i + 1, cols):
                res += (from_to[i][j] - 1) * from_to[i][j] // 2
        return res


class Test(unittest.TestCase):
    def test(self):
        grid = [
            [1, 0, 0, 1, 0],
            [0, 0, 1, 0, 1],
            [0, 0, 0, 1, 0],
            [1, 0, 1, 0, 1]
        ]
        out = 1
        self.assertEqual(Solution().countCornerRectangles(grid), out)
        grid = [
            [1, 1, 1],
            [1, 1, 1],
            [1, 1, 1]
        ]
        out = 9
        self.assertEqual(Solution().countCornerRectangles(grid), out)
        grid = [
            [1] * 200
            for _ in range(200)
        ]
        out = 396010000
        self.assertEqual(Solution().countCornerRectangles(grid), out)
