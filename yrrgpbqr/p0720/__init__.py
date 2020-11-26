import unittest
from typing import List


class Solution:
    def longestWord(self, words: List[str]) -> str:
        buildable_words = {""}
        for word in sorted(words, key=lambda x: len(x)):
            if word[:-1] in buildable_words:
                buildable_words.add(word)
        return sorted(buildable_words, key=lambda x: (-len(x), x))[0]


class Test(unittest.TestCase):
    def test(self):
        words = ["w", "wo", "wor", "worl", "world"]
        self.assertEqual(
            "world",
            Solution().longestWord(words)
        )
        words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
        self.assertEqual(
            "apple",
            Solution().longestWord(words)
        )
