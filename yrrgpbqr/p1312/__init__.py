import unittest
from typing import List


class Solution:
    def minInsertions(self, s: str) -> int:
        cache = {}

        def inner(l, r):
            if l >= r:
                return 0
            if (l, r) not in cache:
                if s[l] == s[r]:
                    cache[(l, r)] = inner(l + 1, r - 1)
                else:
                    cache[(l, r)] = 1 + min(inner(l + 1, r), inner(l, r - 1))
            return cache[(l, r)]

        return inner(0, len(s) - 1)


class Test(unittest.TestCase):
    def test(self):
        s = "zzazz"
        out = 0
        self.assertEqual(Solution().minInsertions(s), out)
        s = "mbadm"
        out = 2
        self.assertEqual(Solution().minInsertions(s), out)
        s = "leetcode"
        out = 5
        self.assertEqual(Solution().minInsertions(s), out)
        s = "g"
        out = 0
        self.assertEqual(Solution().minInsertions(s), out)
        s = "no"
        out = 1
        self.assertEqual(Solution().minInsertions(s), out)
