import unittest
from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        res = []
        for digit in reversed(digits):
            digit += carry
            res.append(digit % 10)
            carry = digit // 10
        if carry > 0:
            res.append(carry)
        return list(reversed(res))


class Test(unittest.TestCase):
    def test(self):
        digits = [1, 2, 3]
        out = [1, 2, 4]
        self.assertEqual(Solution().plusOne(digits), out)
        digits = [9, 9, 9]
        out = [1, 0, 0, 0]
        self.assertEqual(Solution().plusOne(digits), out)
