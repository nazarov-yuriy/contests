import unittest
from typing import List


class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if s == "":
            return 0
        is_palindrome = True
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]:
                is_palindrome = False
            l += 1
            r -= 1
        return 1 if is_palindrome else 2


class Test(unittest.TestCase):
    def test(self):
        s = "ababa"
        out = 1
        self.assertEqual(Solution().removePalindromeSub(s), out)
        s = "abb"
        out = 2
        self.assertEqual(Solution().removePalindromeSub(s), out)
        s = "baabb"
        out = 2
        self.assertEqual(Solution().removePalindromeSub(s), out)
        s = ""
        out = 0
        self.assertEqual(Solution().removePalindromeSub(s), out)
