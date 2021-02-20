import unittest
from typing import List


class Solution:
    def romanToInt(self, s: str) -> int:
        res = 0
        pos = 0
        seqs = {
            'IV': 4,
            'IX': 9,
            'XL': 40,
            'XC': 90,
            'CD': 400,
            'CM': 900,
        }
        digits = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000,
        }
        while pos < len(s):
            if s[pos:pos+2] in seqs:
                res += seqs[s[pos:pos+2]]
                pos += 2
            else:
                res += digits[s[pos]]
                pos += 1
        return res


class Test(unittest.TestCase):
    def test(self):
        s = "III"
        out = 3
        self.assertEqual(Solution().romanToInt(s), out)
        s = "IV"
        out = 4
        self.assertEqual(Solution().romanToInt(s), out)
