import unittest
from typing import List


class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        to_visit = set()
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    to_visit.add((i, j))
        component_id = 1
        component_ids = [[0] * len(row) for row in grid]
        component_coords = set()
        component_coord = set()
        component_min_row = rows
        component_min_col = cols

        def walk(i, j):
            nonlocal component_min_row
            nonlocal component_min_col
            component_coord.add((i, j))
            component_min_row = min(component_min_row, i)
            component_min_col = min(component_min_col, j)
            to_visit.remove((i, j))
            for ni, nj in [(i, j - 1), (i, j + 1), (i - 1, j), (i + 1, j)]:
                if 0 <= ni < rows and 0 <= nj < cols and (ni, nj) in to_visit:
                    walk(ni, nj)

        while len(to_visit) > 0:
            i, j = next(iter(to_visit))
            walk(i, j)
            component_coords.add(
                tuple((i - component_min_row, j - component_min_col) for i, j in sorted(component_coord)))
            component_id += 1
            component_min_row = rows
            component_min_col = cols
            component_coord = set()

        return len(component_coords)


class Test(unittest.TestCase):
    def test(self):
        grid = [[1, 1, 0, 0, 0], [1, 1, 0, 0, 0], [0, 0, 0, 1, 1], [0, 0, 0, 1, 1]]
        out = 1
        self.assertEqual(Solution().numDistinctIslands(grid), out)
