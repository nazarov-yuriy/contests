import unittest
from typing import List


class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        while n not in seen:
            seen.add(n)
            next_n = 0
            while n:
                next_n += (n % 10) ** 2
                n = n // 10
            n = next_n
        return n == 1


class Test(unittest.TestCase):
    def test(self):
        n = 19
        out = True
        self.assertEqual(Solution().isHappy(n), out)
        n = 2
        out = False
        self.assertEqual(Solution().isHappy(n), out)
