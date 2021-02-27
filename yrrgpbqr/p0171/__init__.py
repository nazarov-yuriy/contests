import unittest
from typing import List


class Solution:
    def titleToNumber(self, s: str) -> int:
        res = 0
        for i, char in enumerate(reversed(s)):
            res += (ord(char) - ord('A')) * (26 ** i) + (26 ** i)
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "A"
        out = 1
        self.assertEqual(Solution().titleToNumber(s), out)
        s = "AB"
        out = 28
        self.assertEqual(Solution().titleToNumber(s), out)
        s = "ZY"
        out = 701
        self.assertEqual(Solution().titleToNumber(s), out)
        s = "FXSHRXW"
        out = 2 ** 31 - 1
        self.assertEqual(Solution().titleToNumber(s), out)
