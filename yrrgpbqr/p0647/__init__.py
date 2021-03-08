import unittest
from typing import List


class Solution:
    def countSubstrings(self, s: str) -> int:
        is_palindrome = [[None] * (len(s) + 1) for _ in range(len(s))]
        res = 0
        for l in range(len(s)):  # len = 0
            is_palindrome[l][l] = True
        for l in range(len(s)):  # len = 1
            is_palindrome[l][l + 1] = True
            res += 1
        for length in range(2, len(s) + 1):
            for l in range(len(s) + 1 - length):
                r = l + length
                if s[l] == s[r - 1] and is_palindrome[l + 1][r - 1]:
                    is_palindrome[l][r] = True
                    res += 1
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "abc"
        out = 3
        self.assertEqual(Solution().countSubstrings(s), out)
        s = "aaa"
        out = 6
        self.assertEqual(Solution().countSubstrings(s), out)
