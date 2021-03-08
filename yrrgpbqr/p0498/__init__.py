import unittest
from typing import List


class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0:
            return []
        rows, cols = len(matrix), len(matrix[0])
        r, c = 0, 0
        dirs = [(-1, 1), (1, -1)]
        dir = 0
        res = []
        while True:
            res.append(matrix[r][c])
            if r == rows - 1 and c == cols - 1:
                break
            assert len(res) <= rows * cols
            dr, dc = dirs[dir]
            r += dr
            c += dc
            if r < 0:
                dir = (dir + 1) % 2
                if c < cols:
                    r = 0
                else:
                    r = 1
                    c = cols - 1
            if c < 0:
                dir = (dir + 1) % 2
                if r < rows:
                    c = 0
                else:
                    c = 1
                    r = rows - 1
            if r >= rows:
                dir = (dir + 1) % 2
                r = rows - 1
                c += 2
            if c >= cols:
                dir = (dir + 1) % 2
                c = cols - 1
                r += 2
        return res


class Test(unittest.TestCase):
    def test(self):
        matrix = [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]
        ]
        out = [1,2,4,7,5,3,6,8,9]
        self.assertEqual(Solution().findDiagonalOrder(matrix), out)
