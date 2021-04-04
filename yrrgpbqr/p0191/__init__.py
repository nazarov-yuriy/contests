import unittest
from typing import List


class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        while n:
            res += n & 1
            n >>= 1
        return res


class Test(unittest.TestCase):
    def test(self):
        n = 11
        out = 3
        self.assertEqual(Solution().hammingWeight(n), out)
        n = 64
        out = 1
        self.assertEqual(Solution().hammingWeight(n), out)
        n = 0b11111111111111111111111111111101
        out = 31
        self.assertEqual(Solution().hammingWeight(n), out)