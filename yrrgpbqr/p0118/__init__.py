import unittest
from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        for rowIndex in range(1, numRows + 1):
            row = [1]
            for pos in range(1, rowIndex):
                row.append(sum(res[-1][pos - 1:pos + 1]))
            res.append(row)
        return res


class Test(unittest.TestCase):
    def test(self):
        numRows = 5
        out = [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
        self.assertEqual(Solution().generate(numRows), out)
        numRows = 1
        out = [[1]]
        self.assertEqual(Solution().generate(numRows), out)
