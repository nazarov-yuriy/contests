import unittest
from typing import List


class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        k -= n
        rev_res = []
        for _ in range(n):
            char = min(25, k)
            k -= char
            rev_res.append(chr(ord("a") + char))
        return "".join(reversed(rev_res))


class Test(unittest.TestCase):
    def test(self):
        n = 3
        k = 27
        self.assertEqual(Solution().getSmallestString(n, k), "aay")
        n = 5
        k = 73
        self.assertEqual(Solution().getSmallestString(n, k), "aaszz")
