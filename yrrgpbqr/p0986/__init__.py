import unittest
from typing import List


class Solution:
    def intersection(self, la, ra, lb, rb):
        l = max(la, lb)
        r = min(ra, rb)
        if l <= r:
            return [l, r]
        else:
            return None

    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        res = []
        a_iter = iter(A)
        b_iter = iter(B)
        try:
            la, ra = next(a_iter)
            lb, rb = next(b_iter)
            while True:
                intersection = self.intersection(la, ra, lb, rb)
                if intersection is not None:
                    res.append(intersection)
                if ra >= rb:
                    lb, rb = next(b_iter)
                else:
                    la, ra = next(a_iter)
        except StopIteration:
            pass
        return res


class Test(unittest.TestCase):
    def test(self):
        A = [[0, 2], [5, 10], [13, 23], [24, 25]]
        B = [[1, 5], [8, 12], [15, 24], [25, 26]]
        O = [[1, 2], [5, 5], [8, 10], [15, 23], [24, 24], [25, 25]]
        self.assertEqual(Solution().intervalIntersection(A, B), O)
        B = [[0, 2], [5, 10], [13, 23], [24, 25]]
        A = [[1, 5], [8, 12], [15, 24], [25, 26]]
        O = [[1, 2], [5, 5], [8, 10], [15, 23], [24, 24], [25, 25]]
        self.assertEqual(Solution().intervalIntersection(A, B), O)
        A = [[0, 2], [5, 10], [13, 23], [24, 25]]
        B = []
        O = []
        self.assertEqual(Solution().intervalIntersection(A, B), O)
        A = []
        B = [[1, 5], [8, 12], [15, 24], [25, 26]]
        O = []
        self.assertEqual(Solution().intervalIntersection(A, B), O)
