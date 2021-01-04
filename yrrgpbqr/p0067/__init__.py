import unittest
from typing import List
from itertools import zip_longest


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = []
        carry = 0
        for digit_a, digit_b in zip_longest(reversed(a), reversed(b)):
            s = int(digit_a or "0") + int(digit_b or "0") + carry
            res.append(str(s % 2))
            carry = s // 2
        if carry:
            res.append("1")
        return "".join(reversed(res))


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(Solution().addBinary("11", "1"), "100")
        self.assertEqual(Solution().addBinary("1010", "1011"), "10101")
