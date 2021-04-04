import unittest
from typing import List
import collections


class Solution:
    def largestUniqueNumber(self, A: List[int]) -> int:
        c = collections.Counter(A)
        c[-1] = 1
        return max(x for x in c if c[x] == 1)


class Test(unittest.TestCase):
    def test(self):
        A = [5, 7, 3, 9, 4, 9, 8, 3, 1]
        out = 8
        self.assertEqual(Solution().largestUniqueNumber(A), out)
