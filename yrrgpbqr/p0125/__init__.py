import unittest
from typing import List


class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        s = s.lower()
        while l < r:
            if (not ('a' <= s[l] <= 'z')) and (not ('0' <= s[l] <= '9')):
                l += 1
            elif (not ('a' <= s[r] <= 'z')) and (not ('0' <= s[r] <= '9')):
                r -= 1
            elif s[l] == s[r]:
                l += 1
                r -= 1
            else:
                return False
        return True


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().isPalindrome("A man, a plan, a canal: Panama"), True)
        self.assertEqual(Solution().isPalindrome("race a car"), False)
