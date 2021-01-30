import unittest
from typing import List
import collections


class Solution:
    EMPTY = 0
    BUILDING = 1
    OBSTACLE = 2

    def shortestDistance(self, grid: List[List[int]]) -> int:
        INF = float("inf")
        rows = len(grid)
        cols = len(grid[0])
        starts = []
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == self.BUILDING:
                    starts.append((r, c))
        total_distances = [[0] * cols for _ in range(rows)]
        for sr, sc in starts:
            distances = [[INF] * cols for _ in range(rows)]
            queue = collections.deque([(sr, sc, 0)])
            seen = {(sr, sc)}
            while len(queue) > 0:
                r, c, distance = queue.popleft()
                distances[r][c] = distance
                for nr, nc in [(r, c - 1), (r, c + 1), (r - 1, c), (r + 1, c)]:
                    if 0 <= nr < rows and 0 <= nc < cols:
                        if grid[nr][nc] == self.EMPTY and (nr, nc) not in seen:
                            seen.add((nr, nc))
                            queue.append((nr, nc, distance + 1))
            distances[sr][sc] = INF
            for r in range(rows):
                for c in range(cols):
                    total_distances[r][c] += distances[r][c]
        res = min(min(row) for row in total_distances)
        if res < INF:
            return res
        else:
            return -1


class Test(unittest.TestCase):
    def test(self):
        grid = [[1, 0, 2, 0, 1], [0, 0, 0, 0, 0], [0, 0, 1, 0, 0]]
        out = 7
        self.assertEqual(Solution().shortestDistance(grid), out)
        grid = [[1]]
        out = -1
        self.assertEqual(Solution().shortestDistance(grid), out)
