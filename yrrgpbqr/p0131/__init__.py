import unittest
from typing import List


class Solution:
    def partition(self, s: str) -> List[List[str]]:
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
        res = []
        stack = []

        def inner(l):
            if l == len(s):
                res.append(list(stack))
            for r in range(l, len(s)):
                if isPalindrome[l][r]:
                    stack.append(s[l:r + 1])
                    inner(r + 1)
                    stack.pop()

        inner(0)
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "aab"
        out = [["a", "a", "b"], ["aa", "b"]]
        self.assertEqual(Solution().partition(s), out)
        s = "a"
        out = [["a"]]
        self.assertEqual(Solution().partition(s), out)
