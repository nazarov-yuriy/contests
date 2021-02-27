import unittest
from typing import List


class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        res = 0
        while True:
            if X >= Y:
                return res + X - Y
            if Y % 2 == 1:
                res += 1
                Y += 1
            else:
                res += 1
                Y //= 2


class Test(unittest.TestCase):
    def test(self):
        X = 2
        Y = 3
        out = 2
        self.assertEqual(Solution().brokenCalc(X, Y), out)
        X = 5
        Y = 8
        out = 2
        self.assertEqual(Solution().brokenCalc(X, Y), out)
        X = 3
        Y = 10
        out = 3
        self.assertEqual(Solution().brokenCalc(X, Y), out)
        X = 1024
        Y = 1
        out = 1023
        self.assertEqual(Solution().brokenCalc(X, Y), out)
