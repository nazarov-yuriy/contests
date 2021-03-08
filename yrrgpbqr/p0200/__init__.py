import unittest
from typing import List
import collections


class Solution:
    LAND = "1"

    def numIslands(self, grid: List[List[str]]) -> int:
        seen = [[False] * len(row) for row in grid]
        res = 0
        rows = len(grid)
        cols = len(grid[0])
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == self.LAND and not seen[r][c]:
                    res += 1
                    queue = collections.deque([(r, c)])
                    seen[r][c] = True
                    while len(queue) > 0:
                        cur_r, cur_c = queue.popleft()
                        for dr, dc in [(0, -1), (0, 1), (-1, 0), (1, 0)]:
                            new_r, new_c = cur_r + dr, cur_c + dc
                            if 0 <= new_r < rows and 0 <= new_c < cols and grid[new_r][new_c] == self.LAND and not seen[new_r][new_c]:
                                queue.append((new_r, new_c))
                                seen[new_r][new_c] = True
        return res


class Test(unittest.TestCase):
    def test(self):
        grid = [
            ["1", "1", "1", "1", "0"],
            ["1", "1", "0", "1", "0"],
            ["1", "1", "0", "0", "0"],
            ["0", "0", "0", "0", "0"]
        ]
        out = 1
        self.assertEqual(Solution().numIslands(grid), out)
        grid = [
            ["1", "1", "0", "0", "0"],
            ["1", "1", "0", "0", "0"],
            ["0", "0", "1", "0", "0"],
            ["0", "0", "0", "1", "1"]
        ]
        out = 3
        self.assertEqual(Solution().numIslands(grid), out)
