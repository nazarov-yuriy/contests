import unittest
from collections import Counter


class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        odd = [x for x in Counter(s).values() if x % 2 == 1]
        return len(odd) <= 1


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().canPermutePalindrome("code"), False)
        self.assertEqual(Solution().canPermutePalindrome("aab"), True)
        self.assertEqual(Solution().canPermutePalindrome("carerac"), True)
        self.assertEqual(Solution().canPermutePalindrome(""), True)
        self.assertEqual(Solution().canPermutePalindrome("c"), True)
