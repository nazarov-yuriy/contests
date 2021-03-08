import unittest
from typing import List


class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        prev, res = 0, 0
        key_pos = {k: i for i, k in enumerate(keyboard)}
        for char in word:
            res += abs(key_pos[char] - prev)
            prev = key_pos[char]
        return res


class Test(unittest.TestCase):
    def test(self):
        keyboard = "abcdefghijklmnopqrstuvwxyz"
        word = "cba"
        out = 4
        self.assertEqual(Solution().calculateTime(keyboard, word), out)
