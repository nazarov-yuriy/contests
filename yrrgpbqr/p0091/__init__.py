import unittest
from typing import List


class Solution:
    def numDecodings(self, s: str) -> int:
        res = [0] * (len(s) + 1)
        res[-1] = 1  # fake
        res[-2] = 1 if s[-1] != "0" else 0  # last
        for i in range(len(s) - 2, -1, -1):
            if s[i] != "0":
                res[i] += res[i + 1]
            if "10" <= s[i:i + 2] <= "26":
                res[i] += res[i + 2]
        return res[0]


class Test(unittest.TestCase):
    def test(self):
        s = "12"
        out = 2
        self.assertEqual(Solution().numDecodings(s), out)
        s = "226"
        out = 3
        self.assertEqual(Solution().numDecodings(s), out)
        s = "0"
        out = 0
        self.assertEqual(Solution().numDecodings(s), out)
        s = "06"
        out = 0
        self.assertEqual(Solution().numDecodings(s), out)
