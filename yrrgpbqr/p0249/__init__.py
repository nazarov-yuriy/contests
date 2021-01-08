import unittest
from typing import List



class Solution:
    ALPHABET_SIZE = 26

    def calcKey(self, s: str):
        res = []
        if len(s) > 0:
            res.append(0)
            for char in s[1:]:
                res.append((ord(char) + self.ALPHABET_SIZE - ord(s[0])) % self.ALPHABET_SIZE)
        return tuple(res)

    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        res = {}
        for s in strings:
            res.setdefault(self.calcKey(s), []).append(s)
        return list(res.values())


class Test(unittest.TestCase):
    def test(self):
        strings = ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"]
        out = [
            ["abc","bcd","xyz"],
            ["acef"],
            ["az","ba"],
            ["a","z"]
        ]
        self.assertEqual(Solution().groupStrings(strings), out)
