import unittest
from typing import List


class Solution:
    def trailingZeroes(self, n: int) -> int:
        power2 = 0
        power5 = 0
        for i in range(2, n + 1):
            while i % 2 == 0:
                i //= 2
                power2 += 1
            while i % 5 == 0:
                i //= 5
                power5 += 1
        return min(power2, power5)


class Test(unittest.TestCase):
    def test(self):
        n = 3
        out = 0
        self.assertEqual(Solution().trailingZeroes(n), out)
        n = 5
        out = 1
        self.assertEqual(Solution().trailingZeroes(n), out)
        n = 0
        out = 0
        self.assertEqual(Solution().trailingZeroes(n), out)
