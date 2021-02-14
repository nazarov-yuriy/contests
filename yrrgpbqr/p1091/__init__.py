import unittest
from typing import List
import collections


class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        if grid[0][0] != 0:
            return -1
        queue = collections.deque([(0, 0, 1)])
        seen = {(0, 0)}
        while len(queue):
            r, c, d = queue.popleft()
            if r == rows - 1 and c == cols - 1:
                return d
            for nr, nc in [
                (r - 1, c - 1), (r - 1, c), (r - 1, c + 1),
                (r, c - 1), (r, c + 1),
                (r + 1, c - 1), (r + 1, c), (r + 1, c + 1),
            ]:
                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 0 and (nr, nc) not in seen:
                    queue.append((nr, nc, d + 1))
                    seen.add((nr, nc))
        return -1


class Test(unittest.TestCase):
    def test(self):
        grid = [[0, 1], [1, 0]]
        self.assertEqual(Solution().shortestPathBinaryMatrix(grid), 2)
