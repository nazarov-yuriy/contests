import unittest
from typing import List
import collections


class Solution:
    def originalDigits(self, s: str) -> str:
        digit_reprs = {
            0: "zero",  # z
            1: "one",  # i
            2: "two",  # w
            3: "three",  # r
            4: "four",  # u
            5: "five",  # v
            6: "six",  # x
            7: "seven",  # s
            8: "eight",  # h
            9: "nine",  #
        }
        digits_char_count = {d: collections.Counter(repr) for d, repr in digit_reprs.items()}
        char_count = collections.Counter(s)
        res = collections.Counter()
        for digit in [0, 2, 4, 6, 3, 8, 7, 5, 1, 9]:
            digit_char_count = digits_char_count[digit]
            while digit_char_count == (digit_char_count & char_count):
                res[digit] += 1
                char_count -= digit_char_count
        return "".join(str(x) for x in sorted(res.elements()))


class Test(unittest.TestCase):
    def test(self):
        s = "owoztneoer"
        out = "012"
        self.assertEqual(Solution().originalDigits(s), out)
        s = "fviefuro"
        out = "45"
        self.assertEqual(Solution().originalDigits(s), out)
