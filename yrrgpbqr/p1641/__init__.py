import unittest
from typing import List


class Solution:
    def countVowelStrings(self, n: int) -> int:
        chars = 5
        res = [[0]*chars for _ in range(n)]
        for i in range(chars):
            res[0][i] = i+1
        for j in range(1, n):
            s = 0
            for i in range(chars):
                s += res[j-1][i]
                res[j][i] = s
        return res[n-1][-1]


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().countVowelStrings(1), 5)
        self.assertEqual(Solution().countVowelStrings(2), 15)
        self.assertEqual(Solution().countVowelStrings(33), 66045)
