import unittest
from typing import List
import collections


class Solution:
    def minDeletions(self, s: str) -> int:
        counts = collections.Counter(s)
        next_cnt = len(s)
        res = 0
        for c in reversed(list(sorted(counts.values()))):
            if c > next_cnt:
                res += c - next_cnt
                if next_cnt > 0:
                    next_cnt -= 1
            else:
                next_cnt = c - 1
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "aab"
        out = 0
        self.assertEqual(Solution().minDeletions(s), out)
        s = "aaabbbcc"
        out = 2
        self.assertEqual(Solution().minDeletions(s), out)
        s = "ceabaacb"
        out = 2
        self.assertEqual(Solution().minDeletions(s), out)
