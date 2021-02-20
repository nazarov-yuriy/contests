import unittest
from typing import List


class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        if len(A) < 2:
            return 0
        ranges = []
        l, r = 0, 1
        while True:
            while r + 1 < len(A) and A[r + 1] - A[r] == A[r] - A[r - 1]:
                r += 1
            ranges.append((l, r))
            if r + 1 < len(A):
                l = r
                r = r + 1
            else:
                break
        res = 0
        for r in ranges:
            l = r[1] - r[0] + 1
            if l >= 3:
                res += (l - 3 + 1) * (l - 3 + 1 + 1) // 2
        return res


class Test(unittest.TestCase):
    def test(self):
        A = [1, 2, 3, 4, 6, 8, 10, 12]
        self.assertEqual(Solution().numberOfArithmeticSlices(A), 9)
