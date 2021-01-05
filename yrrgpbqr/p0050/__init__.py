import unittest
from typing import List


class Solution:
    def myPow(self, x: float, n: int) -> float:
        sign = 1 if n >= 0 else -1
        n = abs(n)
        res = 1.
        pow = 1
        while n > 0:
            if n & pow != 0:
                n -= pow
                res *= x
            x *= x
            pow *= 2
        return res if sign > 0 else 1 / res


class Test(unittest.TestCase):
    def test(self):
        x = 2.00000
        n = 10
        assert abs(Solution().myPow(x, n) - 1024.) < 1e7
        x = 2.10000
        n = 3
        assert abs(Solution().myPow(x, n) - 9.26100) < 1e7
        x = 2.00000
        n = -2
        assert abs(Solution().myPow(x, n) - 0.25) < 1e7
