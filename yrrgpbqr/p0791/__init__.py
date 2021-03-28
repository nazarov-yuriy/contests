import unittest
from typing import List


class Solution:
    def customSortString(self, S: str, T: str) -> str:
        char_pos = {char: pos for pos, char in enumerate(S)}
        return "".join(sorted(T, key=lambda x: char_pos.get(x, -1)))


class Test(unittest.TestCase):
    def test(self):
        S = "cba"
        T = "abcd"
        out = "dcba"
        self.assertEqual(Solution().customSortString(S, T), out)
