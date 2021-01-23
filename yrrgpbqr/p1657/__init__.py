import unittest
from typing import List
import collections


class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        same_counts = sorted(collections.Counter(word1).values()) == sorted(collections.Counter(word2).values())
        same_vals = set(word1) == set(word2)
        return same_counts and same_vals


class Test(unittest.TestCase):
    def test(self):
        word1 = "abc"
        word2 = "bca"
        self.assertEqual(Solution().closeStrings(word1, word2), True)
        word1 = "a"
        word2 = "aa"
        self.assertEqual(Solution().closeStrings(word1, word2), False)
        word1 = "cabbba"
        word2 = "cabbba"
        self.assertEqual(Solution().closeStrings(word1, word2), True)
        word1 = "cabbba"
        word2 = "aabbss"
        self.assertEqual(Solution().closeStrings(word1, word2), False)
        word1 = "aab"
        word2 = "dcc"
        self.assertEqual(Solution().closeStrings(word1, word2), False)
