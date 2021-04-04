import unittest
from typing import List


class Solution:
    def minCut(self, s: str) -> int:
        isPalindrome = [[None] * len(s) for _ in s]
        for palindrome_len in range(1, len(s) + 1):
            for l in range(len(s)):
                r = l + palindrome_len - 1
                if r < len(s):
                    if palindrome_len == 1:
                        isPalindrome[r][l] = True
                    elif palindrome_len == 2:
                        isPalindrome[r][l] = s[l] == s[r]
                    else:
                        isPalindrome[r][l] = s[l] == s[r] and isPalindrome[r - 1][l + 1]
        res = [len(s)] * len(s)
        for m in range(len(s)):
            for i in range(m + 1):
                if isPalindrome[m][i]:
                    prev = res[i - 1] if i > 0 else 0
                    res[m] = min(res[m], prev + 1)
        return res[len(s) - 1] - 1


class Test(unittest.TestCase):
    def test(self):
        s = "aab"
        out = 1
        self.assertEqual(Solution().minCut(s), out)
        s = "a"
        out = 0
        self.assertEqual(Solution().minCut(s), out)
        s = "ab"
        out = 1
        self.assertEqual(Solution().minCut(s), out)