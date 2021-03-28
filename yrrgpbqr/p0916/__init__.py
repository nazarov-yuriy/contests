import unittest
from typing import List
import collections


class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        b_chars = collections.Counter()
        for word in B:
            b_chars |= collections.Counter(word)
        res = []
        for word in A:
            if b_chars == collections.Counter(word) & b_chars:
                res.append(word)
        return res


class Test(unittest.TestCase):
    def test(self):
        A = ["amazon", "apple", "facebook", "google", "leetcode"]
        B = ["e", "o"]
        out = ["facebook", "google", "leetcode"]
        self.assertEqual(Solution().wordSubsets(A, B), out)
