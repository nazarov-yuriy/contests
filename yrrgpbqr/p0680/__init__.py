import unittest
from typing import List


class Solution:
    def validLeftPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        skipped = 0
        while l < r:
            if s[l] != s[r]:
                if skipped == 0:
                    skipped += 1
                    l += 1
                else:
                    return False
            else:
                l += 1
                r -= 1
        return True

    def validPalindrome(self, s: str) -> bool:
        return self.validLeftPalindrome(s) or self.validLeftPalindrome("".join(list(reversed(s))))


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().validPalindrome("aba"), True)
        self.assertEqual(Solution().validPalindrome("abca"), True)
        self.assertEqual(Solution().validPalindrome("abcda"), False)
        self.assertEqual(Solution().validPalindrome("cbbcc"), True)
        self.assertEqual(Solution().validPalindrome("ccbbc"), True)
