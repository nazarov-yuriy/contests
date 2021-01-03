import unittest
from typing import List


class BinaryMatrix(object):
    def __init__(self, matrix):
        self.matrix = matrix

    def get(self, row: int, col: int) -> int:
        return self.matrix[row][col]

    def dimensions(self) -> List:
        return [len(self.matrix), len(self.matrix[0])]


class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        dimensions = binaryMatrix.dimensions()
        candidates = set(range(dimensions[0]))
        res = dimensions[1]
        while candidates:
            candidate = next(iter(candidates))
            while res - 1 >= 0 and binaryMatrix.get(candidate, res - 1):
                res -= 1
            candidates.remove(candidate)
        return res if res < dimensions[0] else -1


class Test(unittest.TestCase):
    def test(self):
        mat = [[0, 0], [1, 1]]
        bm = BinaryMatrix(mat)
        self.assertEqual(Solution().leftMostColumnWithOne(bm), 0)
        mat = [[0, 0], [0, 1]]
        bm = BinaryMatrix(mat)
        self.assertEqual(Solution().leftMostColumnWithOne(bm), 1)
        mat = [[0, 0], [0, 0]]
        bm = BinaryMatrix(mat)
        self.assertEqual(Solution().leftMostColumnWithOne(bm), -1)
        mat = [[0, 0, 0, 1], [0, 0, 1, 1], [0, 1, 1, 1]]
        bm = BinaryMatrix(mat)
        self.assertEqual(Solution().leftMostColumnWithOne(bm), 1)
