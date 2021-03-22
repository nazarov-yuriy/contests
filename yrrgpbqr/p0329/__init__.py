import unittest
from typing import List


class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        vals = {}
        for r, row in enumerate(matrix):
            for c, x in enumerate(row):
                vals.setdefault(x, []).append((r, c))
        lens = [[0] * len(row) for row in matrix]
        res = 0
        for val in sorted(vals):
            for r, c in vals[val]:
                lens[r][c] = 1
                for nr, nc in [(r, c - 1), (r, c + 1), (r - 1, c), (r + 1, c)]:
                    if 0 <= nr < rows and 0 <= nc < cols and matrix[nr][nc] < val:
                        lens[r][c] = max(lens[r][c], lens[nr][nc] + 1)
                res = max(res, lens[r][c])
        return res


class Test(unittest.TestCase):
    def test(self):
        matrix = [[9, 9, 4], [6, 6, 8], [2, 1, 1]]
        out = 4
        self.assertEqual(Solution().longestIncreasingPath(matrix), out)
