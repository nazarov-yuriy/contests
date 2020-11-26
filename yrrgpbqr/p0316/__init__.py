import unittest
from typing import Set


class Solution:
    def removeDuplicateLettersInner(self, s: str, exclude: Set):
        all_chars = set(s) - exclude
        for c in sorted(all_chars):
            pos = s.index(c)
            if all_chars == set(s[pos:]) - exclude:
                return c + self.removeDuplicateLettersInner(s[pos + 1:], exclude | {c})
        return ""

    def removeDuplicateLetters(self, s: str) -> str:
        return self.removeDuplicateLettersInner(s, set())


class Test(unittest.TestCase):
    def test(self):
        s = "bcabc"
        self.assertEqual(
            "abc",
            Solution().removeDuplicateLetters(s)
        )
        s = "cbacdcbc"
        self.assertEqual(
            "acdb",
            Solution().removeDuplicateLetters(s)
        )
