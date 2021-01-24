import unittest
from typing import List


class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        diagonals = []  # r, c
        rows, cols = len(mat), len(mat[0])
        for r0 in range(1, rows):
            diagonals.append(zip(range(r0, rows), range(cols)))
        for c0 in range(cols):
            diagonals.append(zip(range(rows), range(c0, cols)))
        for diagonal in diagonals:
            diagonal = list(diagonal)
            vals = sorted([mat[r][c] for r, c in diagonal])
            for i, (r, c) in enumerate(diagonal):
                mat[r][c] = vals[i]
        return mat


class Test(unittest.TestCase):
    def test(self):
        mat = [[3, 3, 1, 1], [2, 2, 1, 2], [1, 1, 1, 2]]
        out = [[1, 1, 1, 1], [1, 2, 2, 2], [1, 2, 3, 3]]
        self.assertEqual(Solution().diagonalSort(mat), out)
