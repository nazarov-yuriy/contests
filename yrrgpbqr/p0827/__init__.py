import unittest
from typing import List


class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        to_visit = set()
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    to_visit.add((i, j))
        component_id = 1
        component_ids = [[0] * len(row) for row in grid]
        component_size = 0
        component_sizes = {}

        def walk(i, j):
            nonlocal component_size
            component_size += 1
            component_ids[i][j] = component_id
            to_visit.remove((i, j))
            for ni, nj in [(i, j-1), (i, j+1), (i-1, j), (i+1, j)]:
                if 0 <= ni < rows and 0 <= nj < cols and (ni, nj) in to_visit:
                    walk(ni, nj)

        while len(to_visit) > 0:
            i, j = next(iter(to_visit))
            walk(i, j)
            component_sizes[component_id] = component_size
            component_id += 1
            component_size = 0

        if len(component_sizes) == 0:
            return 1
        res = max(component_sizes.values())
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 0:
                    neighbors = set()
                    for ni, nj in [(i, j - 1), (i, j + 1), (i - 1, j), (i + 1, j)]:
                        if 0 <= ni < rows and 0 <= nj < cols and component_ids[ni][nj] and component_ids[ni][nj] != 0:
                            neighbors.add(component_ids[ni][nj])
                    res = max(res, sum(component_sizes[x] for x in neighbors) + 1)
        return res


class Test(unittest.TestCase):
    def test(self):
        grid = [[1, 0], [0, 1]]
        self.assertEqual(Solution().largestIsland(grid), 3)
        grid = [[1, 0], [1, 1]]
        self.assertEqual(Solution().largestIsland(grid), 4)
        grid = [[1, 1], [1, 1]]
        self.assertEqual(Solution().largestIsland(grid), 4)
