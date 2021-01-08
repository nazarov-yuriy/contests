import unittest
from typing import List
from itertools import chain, zip_longest


class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        for a, b in zip_longest(chain(*word1), chain(*word2)):
            if a != b:
                return False
        return True

class Test(unittest.TestCase):
    def test(self):
        word1 = ["ab", "c"]
        word2 = ["a", "bc"]
        self.assertEqual(Solution().arrayStringsAreEqual(word1, word2), True)
        word1 = ["a", "cb"]
        word2 = ["ab", "c"]
        self.assertEqual(Solution().arrayStringsAreEqual(word1, word2), False)
        word1 = ["abc", "d", "defg"]
        word2 = ["abcddefg"]
        self.assertEqual(Solution().arrayStringsAreEqual(word1, word2), True)
