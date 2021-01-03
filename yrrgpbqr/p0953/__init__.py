import unittest
from typing import List


class Solution:
    def map_chars(self, s, order):
        map = {c: chr(ord("a") + i) for i, c in enumerate(order)}
        return "".join(map[c] for c in s)

    def isAlienSorted(self, words: List[str], order: str) -> bool:
        mapped_words = [self.map_chars(word, order) for word in words]
        return mapped_words == sorted(mapped_words)




class Test(unittest.TestCase):
    def test(self):
        words = ["hello", "leetcode"]
        order = "hlabcdefgijkmnopqrstuvwxyz"
        self.assertEqual(Solution().isAlienSorted(words, order), True)
        words = ["word", "world", "row"]
        order = "worldabcefghijkmnpqstuvxyz"
        self.assertEqual(Solution().isAlienSorted(words, order), False)
        words = ["apple", "app"]
        order = "abcdefghijklmnopqrstuvwxyz"
        self.assertEqual(Solution().isAlienSorted(words, order), False)
