import unittest
from typing import List


class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) == 1:
            return ""
        palindrome = list(palindrome)
        for i, char in enumerate(palindrome[:len(palindrome) // 2]):
            if char != 'a':
                palindrome[i] = 'a'
                break
        else:
            palindrome[-1] = 'b'
        return ''.join(palindrome)


class Test(unittest.TestCase):
    def test(self):
        palindrome = "abccba"
        out = "aaccba"
        self.assertEqual(Solution().breakPalindrome(palindrome), out)
        palindrome = "a"
        out = ""
        self.assertEqual(Solution().breakPalindrome(palindrome), out)
        palindrome = "aba"
        out = "abb"
        self.assertEqual(Solution().breakPalindrome(palindrome), out)
