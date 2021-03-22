import unittest
from typing import List
import collections


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        seen = [[False] * len(row) for row in grid]
        max_area = 0
        for sr in range(rows):
            for sc in range(cols):
                if not seen[sr][sc] and grid[sr][sc] == 1:
                    area = 1
                    queue = collections.deque([(sr, sc)])
                    seen[sr][sc] = True
                    while len(queue) > 0:
                        r, c = queue.popleft()
                        for nr, nc in [(r, c - 1), (r, c + 1), (r - 1, c), (r + 1, c)]:
                            if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1 and not seen[nr][nc]:
                                area += 1
                                seen[nr][nc] = True
                                queue.append((nr, nc))
                    max_area = max(max_area, area)
        return max_area


class Test(unittest.TestCase):
    def test(self):
        matrix = [
            [0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
            [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
            [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]
        ]
        out = 6
        self.assertEqual(Solution().maxAreaOfIsland(matrix), out)
        matrix = [[0, 0, 0]]
        out = 0
        self.assertEqual(Solution().maxAreaOfIsland(matrix), out)
