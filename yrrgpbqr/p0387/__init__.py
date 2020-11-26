import unittest
from collections import Counter


class Solution:
    def firstUniqChar(self, s: str) -> int:
        counts = Counter(s)
        for i, c in enumerate(s):
            if counts[c] == 1:
                return i
        return -1


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            0,
            Solution().firstUniqChar("abbecode")
        )
        self.assertEqual(
            2,
            Solution().firstUniqChar("aogeabbecode")
        )
