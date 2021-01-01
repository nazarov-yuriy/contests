import unittest
from itertools import zip_longest


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        res = []
        for row in range(numRows):
            if row == 0 or row == numRows - 1:
                res.extend(s[row::2*numRows-2])
            else:
                res.extend([x for y in zip_longest(s[row::2*numRows-2], s[2 * numRows - 2 - row::2*numRows-2]) for x in y if x is not None])
        return "".join(res)


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            Solution().convert("PAYPALISHIRING", 1),
            "PAYPALISHIRING"
        )
        self.assertEqual(
            Solution().convert("PAYPALISHIRING", 2),
            "PYAIHRNAPLSIIG"
        )
        self.assertEqual(
            Solution().convert("PAYPALISHIRING", 3),
            "PAHNAPLSIIGYIR"
        )
        self.assertEqual(
            Solution().convert("PAYPALISHIRING", 4),
            "PINALSIGYAHRPI"
        )
