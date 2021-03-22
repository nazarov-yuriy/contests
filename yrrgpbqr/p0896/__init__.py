import unittest
from typing import List


class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        incr = True
        decr = True
        for a, b in zip(A[:-1], A[1:]):
            if b < a:
                incr = False
            if b > a:
                decr = False
        return incr or decr


class Test(unittest.TestCase):
    def test(self):
        A = [1, 2, 2, 3]
        out = True
        self.assertEqual(Solution().isMonotonic(A), out)
        A = [1, 2, 2, 1]
        out = False
        self.assertEqual(Solution().isMonotonic(A), out)
