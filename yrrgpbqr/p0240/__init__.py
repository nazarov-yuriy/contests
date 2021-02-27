import unittest
from typing import List


class Solution:
    def binsearch(self, row, l, r, target):
        while r - l > 1:
            m = (l + r) // 2
            if row[m] < target:
                l = m
            else:
                r = m
        return r

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l, r = -1, len(matrix[0])
        for row in matrix:
            r = self.binsearch(row, l, r, target)
            if 0 <= r < len(row) and row[r] == target:
                return True
        return False

class SolutionSlow:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            for el in row:
                if el == target:
                    return True
        return False


class Test(unittest.TestCase):
    def test(self):
        matrix = [
            [1, 4, 7, 11, 15],
            [2, 5, 8, 12, 19],
            [3, 6, 9, 16, 22],
            [10, 13, 14, 17, 24],
            [18, 21, 23, 26, 30]
        ]
        target = 5
        self.assertEqual(Solution().searchMatrix(matrix, target), True)
        self.assertEqual(SolutionSlow().searchMatrix(matrix, target), True)
        matrix = [
            [1, 4, 7, 11, 15],
            [2, 5, 8, 12, 19],
            [3, 6, 9, 16, 22],
            [10, 13, 14, 17, 24],
            [18, 21, 23, 26, 30]
        ]
        target = 20
        self.assertEqual(Solution().searchMatrix(matrix, target), False)
        self.assertEqual(SolutionSlow().searchMatrix(matrix, target), False)
