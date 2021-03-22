import unittest
from typing import List


class Solution:
    def intToRoman(self, num: int) -> str:
        vals = {
            "I": 1,
            "IV": 4,
            "V": 5,
            "IX": 9,
            "X": 10,
            "XL": 40,
            "L": 50,
            "XC": 90,
            "C": 100,
            "CD": 400,
            "D": 500,
            "CM": 900,
            "M": 1000,
        }
        res = ""
        for symbol, val in sorted(vals.items(), key=lambda x: -x[1]):
            while num >= val:
                res += symbol
                num -= val
        return res


class Test(unittest.TestCase):
    def test(self):
        num = 3
        out = "III"
        self.assertEqual(Solution().intToRoman(num), out)
        num = 4
        out = "IV"
        self.assertEqual(Solution().intToRoman(num), out)
        num = 9
        out = "IX"
        self.assertEqual(Solution().intToRoman(num), out)
        num = 58
        out = "LVIII"
        self.assertEqual(Solution().intToRoman(num), out)
        num = 1994
        out = "MCMXCIV"
        self.assertEqual(Solution().intToRoman(num), out)

