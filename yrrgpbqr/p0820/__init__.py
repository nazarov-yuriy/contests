import unittest
from typing import List


class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        trie = {}
        for word in set(words):
            node = trie
            for char in reversed(word):
                node = node.setdefault(char, {})
        res = 0
        for word in set(words):
            node = trie
            for char in reversed(word):
                node = node[char]
            if len(node) == 0:
                res += len(word) + 1
        return res


class Test(unittest.TestCase):
    def test(self):
        words = ["time", "me", "bell"]
        out = 10
        self.assertEqual(Solution().minimumLengthEncoding(words), out)
