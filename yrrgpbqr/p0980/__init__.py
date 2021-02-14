import unittest
from typing import List


class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        START = 1
        END = 2
        EMPTY = 0
        OBSTACLE = -1
        seen = [[False] * len(row) for row in grid]
        rows, cols = len(grid), len(grid[0])
        empty_count = 0
        for r in range(rows):
            for c in range(cols):
                if START == grid[r][c]:
                    sr, sc = r, c
                elif END == grid[r][c]:
                    er, ec = r, c
                elif EMPTY == grid[r][c]:
                    empty_count += 1
        res = 0

        def dfs(r, c, d):
            nonlocal res
            seen[r][c] = True
            if r == er and c == ec and d == empty_count + 1:
                res += 1
            for nr, nc in [(r, c - 1), (r, c + 1), (r - 1, c), (r + 1, c)]:
                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] != OBSTACLE and not seen[nr][nc]:
                    dfs(nr, nc, d + 1)
                pass
            seen[r][c] = False

        dfs(sr, sc, 0)
        return res


class Test(unittest.TestCase):
    def test(self):
        grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
        out = 2
        self.assertEqual(Solution().uniquePathsIII(grid), out)
        grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
        out = 4
        self.assertEqual(Solution().uniquePathsIII(grid), out)
        grid = [[0,1],[2,0]]
        out = 0
        self.assertEqual(Solution().uniquePathsIII(grid), out)
