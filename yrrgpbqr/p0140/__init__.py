import unittest
from typing import List
from itertools import chain


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        cache = {}
        word_dict_lens = set(len(word) for word in wordDict)
        word_dict_set = set(wordDict)

        def inner(start):
            if start == len(s):
                return [[]]
            if start not in cache:
                res = []
                for word_len in word_dict_lens:
                    if start + word_len <= len(s) and s[start:start + word_len] in word_dict_set:
                        word = s[start:start + word_len]
                        for tail in inner(start + word_len):
                            res.append([word] + tail)
                cache[start] = res
            return cache[start]

        return [" ".join(x) for x in inner(0)]


class Test(unittest.TestCase):
    def test(self):
        s = "catsanddog"
        wordDict = ["cat", "cats", "and", "sand", "dog"]
        out = [
            "cats and dog",
            "cat sand dog"
        ]
        self.assertEqual(sorted(Solution().wordBreak(s, wordDict)), sorted(out))
