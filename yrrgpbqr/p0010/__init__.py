import unittest
from typing import List


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if p == "":
            return s == ""
        elif p[1:2] == '*':
            if p[0] == '.':
                for glob_len in range(len(s) + 1):
                    if self.isMatch(s[glob_len:], p[2:]):
                        return True
                return False
            else:
                for glob_len in range(len(s) + 1):
                    if s[:glob_len] == p[0] * glob_len and self.isMatch(s[glob_len:], p[2:]):
                        return True
                return False
        elif p[:1] == '.':
            return s[:1] != "" and self.isMatch(s[1:], p[1:])
        else:
            return p[:1] == s[:1] and self.isMatch(s[1:], p[1:])


class Test(unittest.TestCase):
    def test(self):
        s = "aa"
        p = "a"
        out = False
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "aa"
        p = "a*"
        out = True
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "ab"
        p = ".*"
        out = True
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "aab"
        p = "c*a*b"
        out = True
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "mississippi"
        p = "mis*is*p*."
        out = False
        self.assertEqual(Solution().isMatch(s, p), out)
        s = "a"
        p = ".*..a*"
        out = False
        self.assertEqual(Solution().isMatch(s, p), out)
