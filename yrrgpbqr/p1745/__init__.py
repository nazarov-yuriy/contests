import unittest
from typing import List


class Solution:
    def checkPartitioning(self, s: str) -> bool:
        isPalindrome = [[None] * len(s) for _ in s]
        for palindrome_len in range(1, len(s) + 1):
            for l in range(len(s)):
                r = l + palindrome_len - 1
                if r < len(s):
                    if palindrome_len == 1:
                        isPalindrome[l][r] = True
                    elif palindrome_len == 2:
                        isPalindrome[l][r] = s[l] == s[r]
                    else:
                        isPalindrome[l][r] = s[l] == s[r] and isPalindrome[l + 1][r - 1]
        res1 = [False] * len(s)
        res2 = [False] * len(s)
        res3 = [False] * len(s)
        for m in range(len(s)):
            for i in range(m + 1):
                if isPalindrome[i][m]:
                    if i == 0:
                        res1[m] = True
                    else:
                        res2[m] = res2[m] or res1[i - 1]
                        res3[m] = res3[m] or res2[i - 1]
        return res3[len(s) - 1]


class Test(unittest.TestCase):
    def test(self):
        s = "abcbdd"
        out = True
        self.assertEqual(Solution().checkPartitioning(s), out)
        s = "bcbddxy"
        out = False
        self.assertEqual(Solution().checkPartitioning(s), out)
