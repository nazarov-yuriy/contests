import unittest
from typing import List


bad = 0
def isBadVersion(version: int) -> bool:
    return version >= bad


class Solution:
    def firstBadVersion(self, n: int) -> int:
        l, r = 0, n + 1
        while r - l > 1:
            m = (l + r) // 2
            if isBadVersion(m):
                r = m
            else:
                l = m
        return r


class Test(unittest.TestCase):
    def test(self):
        global bad
        n = 5
        bad = 4
        self.assertEqual(Solution().firstBadVersion(n), bad)
        n = 1
        bad = 1
        self.assertEqual(Solution().firstBadVersion(n), bad)
