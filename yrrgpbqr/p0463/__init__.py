import unittest
from typing import List


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        res = 0
        for r, row in enumerate(grid):
            for c, cell in enumerate(row):
                if cell == 1:
                    if r == 0 or grid[r - 1][c] == 0:
                        res += 1
                    if r == rows - 1 or grid[r + 1][c] == 0:
                        res += 1
                    if c == 0 or grid[r][c - 1] == 0:
                        res += 1
                    if c == cols - 1 or grid[r][c + 1] == 0:
                        res += 1
        return res


class Test(unittest.TestCase):
    def test(self):
        grid = [[0, 1, 0, 0], [1, 1, 1, 0], [0, 1, 0, 0], [1, 1, 0, 0]]
        out = 16
        self.assertEqual(Solution().islandPerimeter(grid), out)
