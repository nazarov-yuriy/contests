import unittest


class SolutionDifferentProblem:
    def longestPalindrome(self, s: str) -> str:
        cache = {}

        def inner(l, r):
            if l >= r:
                return ""
            if l == r - 1:
                return s[l]
            if (l, r) not in cache:
                if s[l] == s[r - 1]:
                    candidate = s[l] + inner(l + 1, r - 1) + s[r - 1]
                else:
                    candidate = ""
                l_candidate = inner(l, r - 1)
                r_candidate = inner(l + 1, r)
                cache[(l, r)] = sorted([l_candidate, candidate, r_candidate], key=len)[-1]
            return cache[(l, r)]

        return inner(0, len(s))


class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s == "":
            return ""
        is_palindrome = [[None] * len(s) for _ in range(len(s))]  # including bounds
        for r in range(len(s)):
            l = r
            is_palindrome[l][r] = True
        max_length = 1
        max_l = 0
        for length in range(2, len(s) + 1):
            for r in range(length - 1, len(s)):
                l = r - length + 1
                is_palindrome[l][r] = s[l] == s[r] and (l + 1 == r or is_palindrome[l + 1][r - 1])
                if is_palindrome[l][r] and length > max_length:
                    max_length = length
                    max_l = l
        return s[max_l: max_l + max_length]


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(
            Solution().longestPalindrome("babad"), "bab"
        )
        self.assertEqual(
            Solution().longestPalindrome("cbbd"), "bb"
        )
        self.assertEqual(
            Solution().longestPalindrome("a"), "a"
        )
        self.assertEqual(
            Solution().longestPalindrome("ac"), "a"
        )
