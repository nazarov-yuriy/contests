import unittest
from typing import List
import collections


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return collections.Counter(s) == collections.Counter(t)


class Test(unittest.TestCase):
    def test(self):
        s = "anagram"
        t = "nagaram"
        self.assertEqual(Solution().isAnagram(s, t), True)
        s = "rat"
        t = "car"
        self.assertEqual(Solution().isAnagram(s, t), False)
