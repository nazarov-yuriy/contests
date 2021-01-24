import unittest
from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        cache = {}
        word_dict_lens = set(len(word) for word in wordDict)
        word_dict_set = set(wordDict)

        def inner(start):
            if start == len(s):
                return 1
            if start not in cache:
                res = -len(s)
                for word_len in word_dict_lens:
                    if start + word_len <= len(s) and s[start:start + word_len] in word_dict_set:
                        word = s[start:start + word_len]
                        res = max(res, inner(start + word_len) + 1)
                cache[start] = res
            return cache[start]

        return inner(0) > 1


class Test(unittest.TestCase):
    def test(self):
        s = "catsanddog"
        wordDict = ["cat", "cats", "and", "sand", "dog"]
        self.assertEqual(Solution().wordBreak(s, wordDict), True)
        s = ""
        wordDict = ["cat", "cats", "and", "sand", "dog"]
        self.assertEqual(Solution().wordBreak(s, wordDict), False)
        s = "catsandog"
        wordDict = ["cats", "dog", "sand", "and", "cat"]
        self.assertEqual(Solution().wordBreak(s, wordDict), False)
