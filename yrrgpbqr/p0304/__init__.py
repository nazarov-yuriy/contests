import unittest
from typing import List


class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        rows = len(matrix)
        if rows > 0:
            cols = len(matrix[0])
        else:
            cols = 0
        self.prefix_sum = [[0] * (cols + 1) for _ in range(rows + 1)]
        for r in range(rows):
            s = 0
            for c in range(cols):
                s += matrix[r][c]
                self.prefix_sum[r + 1][c + 1] = s + self.prefix_sum[r][c + 1]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        res = 0
        res += self.prefix_sum[row2 + 1][col2 + 1]
        res -= self.prefix_sum[row2 + 1][col1]
        res -= self.prefix_sum[row1][col2 + 1]
        res += self.prefix_sum[row1][col1]
        return res


class Test(unittest.TestCase):
    def test(self):
        matrix = [
            [3, 0, 1, 4, 2],
            [5, 6, 3, 2, 1],
            [1, 2, 0, 1, 5],
            [4, 1, 0, 1, 7],
            [1, 0, 3, 0, 5]
        ]
        obj = NumMatrix(matrix)
        row1, col1, row2, col2 = 2, 1, 4, 3
        out = 8
        self.assertEqual(obj.sumRegion(row1, col1, row2, col2), out)
        row1, col1, row2, col2 = 1, 1, 2, 2
        out = 11
        self.assertEqual(obj.sumRegion(row1, col1, row2, col2), out)
        row1, col1, row2, col2 = 1, 2, 2, 4
        out = 12
        self.assertEqual(obj.sumRegion(row1, col1, row2, col2), out)
